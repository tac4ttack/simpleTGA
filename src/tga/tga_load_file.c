/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:02:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/15 18:16:46 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"
#include "simple_tga_parser_tester.h"

// void tga_print_header(t_tga_header *header, const char *target)
// {
// 	fprintf(stdout,
// 			"\nTGA HEADER (%s) =\n"
// 			"\tid_len = %hhd\n\tcm_type = %hhd\n\timg_type = %hhd"
// 			"\n\tcm_first_entry = %hu\n\tcm_length = %hu\n"
// 			"\tcm_bpp = %hhu\n\tx_origin = %hu\n\ty_origin = "
// 			"%hu\n\timage_width = %hu\n\timage_height = %hu\n"
// 			"\tpixel_depth = %hhu\n\n\timage_descriptor_bits = %c%c%c%c%c%c%c%c\n\n",
// 			target,
// 			header->id_len,
// 			header->cm_type,
// 			header->img_type,
// 			header->cm_first_entry,
// 			header->cm_length,
// 			header->cm_bpp,
// 			header->x_origin,
// 			header->y_origin,
// 			header->image_width,
// 			header->image_heigth,
// 			header->pixel_depth,
// 			BYTE_TO_BINARY(header->image_descriptor));

// 			sprintf(tga_info,
// 			"\tid_len = %hhd\n\tcm_type = %hhd\n\timg_type = %hhd"
// 			"\n\tcm_first_entry = %hu\n\tcm_length = %hu\n"
// 			"\tcm_bpp = %hhu\n\tx_origin = %hu\n\ty_origin = "
// 			"%hu\n\timage_width = %hu\n\timage_height = %hu\n"
// 			"\tpixel_depth = %hhu\n\timage_descriptor_bits = %c%c%c%c%c%c%c%c\n\n",
// 			header->id_len,
// 			header->cm_type,
// 			header->img_type,
// 			header->cm_first_entry,
// 			header->cm_length,
// 			header->cm_bpp,
// 			header->x_origin,
// 			header->y_origin,
// 			header->image_width,
// 			header->image_heigth,
// 			header->pixel_depth,
// 			BYTE_TO_BINARY(header->image_descriptor));
// }

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
		if (dst->header->id_len > 0)
			dst->id = (char*)(data + sizeof(t_tga_header));
		if (strcmp(dst->signature, "TRUEVISION-XFILE.") == 0)
		{
			dst->extension_offset = *(char*)(data + dst->file_size - 26);
			dst->developer_offset = *(char*)(data + dst->file_size - 22);
		}
		dst->data_offset = sizeof(t_tga_header) + dst->header->id_len \
							+ dst->header->cm_length;
		return (0);
	}
	return (-1);
}

unsigned int *tga_load_file(const char *target, \
							size_t *width, \
							size_t *height, \
							size_t *bpp)
{
	t_tga_info tga;

	if (target)
	{
		bzero(&tga, sizeof(t_tga_info));
		if (!(tga.data = tga_process_file(target, &tga.file_size)))
			return (tga_error("Could not read target file", tga.data));
		if (tga.file_size <= sizeof(t_tga_header))
			return (tga_error("Empty or corrupted TGA file", tga.data));
		if (tga_fill_info(&tga, tga.data) != 0)
			return (tga_error("Error during header decryption", tga.data));

		// DEBUGGING
		// tga_print_header(tga.header, target);

		*width = (width ? tga.width : 0);
		*height = (height ? tga.height : 0);
		*bpp = (bpp ? tga.depth : 0);
		return tga_process_pixels(&tga);
	}
	return NULL;
}
