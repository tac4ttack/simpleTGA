/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:02:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/15 18:17:22 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"
#include "simple_tga_parser_tester.h"

static void tga_print_header(t_tga_header *header, const char *target)
{
	fprintf(stdout,
			"\nTGA HEADER (%s) =\n"
			"\tid_length = %hhd\n\tcolor_map_type = %hhd\n\timage_type = %hhd"
			"\n\tfirst_entry_index = %hu\n\tcolor_map_length = %hu\n"
			"\tcolor_map_entry_size = %hhu\n\tx_origin = %hu\n\ty_origin = "
			"%hu\n\timage_width = %hu\n\timage_height = %hu\n"
			"\tpixel_depth = %hhu\n",
			target,
			header->id_length,
			header->color_map_type,
			header->image_type,
			header->first_entry_index,
			header->color_map_length,
			header->color_map_entry_size,
			header->x_origin,
			header->y_origin,
			header->image_width,
			header->image_heigth,
			header->pixel_depth);
	fprintf(stdout, "\timage_descriptor_bits = " BYTE_TO_BINARY_PATTERN "\n\n",
			BYTE_TO_BINARY(header->image_descriptor));
}

static unsigned short tga_get_origin(const unsigned char descriptor)
{
	if (!(descriptor & 0x20) && !(descriptor & 0x10))
		return (TGA_IMG_ORI_BL);
	else if (!(descriptor & 0x20) && (descriptor & 0x10))
		return (TGA_IMG_ORI_BR);
	else if ((descriptor & 0x20) && !(descriptor & 0x10))
		return (TGA_IMG_ORI_TL);
	else if ((descriptor & 0x20) && (descriptor & 0x10))
		return (TGA_IMG_ORI_TR);
	else
		return (-1);
}

static int tga_fill_info(t_tga_info *dst, void *data)
{
	if (dst && data)
	{
		dst->header = (t_tga_header *)data;
		dst->image_origin = tga_get_origin(dst->header->image_descriptor);
		dst->width = dst->header->image_width;
		dst->height = dst->header->image_heigth;
		dst->depth = dst->header->pixel_depth;
		dst->pixels_nbytes = dst->width * dst->height * (dst->depth / 8);
		dst->signature = (char*)(data + dst->file_size - 18);
		if (dst->header->id_length > 0)
			dst->id = (char*)(data + sizeof(t_tga_header));
		if (strcmp(dst->signature, "TRUEVISION-XFILE.") == 0)
		{
			dst->extension_offset = *(char*)(data + dst->file_size - 26);
			dst->developer_offset = *(char*)(data + dst->file_size - 22);
		}
		return (0);
	}
	return (-1);
}

unsigned int *tga_load_file(const char *target, size_t *width, size_t *height)
{
	t_tga_info tga;

	*width = 0;
	*height = 0;
	if (target)
	{
		bzero(&tga, sizeof(t_tga_info));
		if (!(tga.data = tga_process_file(target, &tga.file_size)))
			return (tga_error("Could not read target file", tga.data));

		if (tga.file_size <= sizeof(t_tga_header))
			return (tga_error("Empty or corrupted TGA file", tga.data));

		if (tga_fill_info(&tga, tga.data) != 0)
			return (tga_error("Error during header decryption", tga.data));

		// fprintf(stdout, "file_size = %zu\npixels_nbytes = %zu\nima_ori = %u\ndepth = %zu| w = %zu | h = %zu\n",
		// 		tga.file_size, tga.pixels_nbytes, tga.image_origin, tga.depth, tga.width, tga.height);
		tga_print_header(tga.header, target);

		if (tga.header->image_type == TGA_TYPE_RAW_TC \
			&& (tga.depth == 32 || tga.depth == 24 \
				|| tga.depth == 16 || tga.depth == 8) \
			&& tga.header->color_map_type == 0)
			return (tga_process_pixels(&tga, width, height));
		else
			return (tga_error("File is not a TGA RAW TRUECOLOR", tga.data));
	}
	return NULL;
}
