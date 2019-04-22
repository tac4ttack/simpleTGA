/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:02:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/18 10:24:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"
#include "simple_tga_parser_tester.h"

void tga_print_header(t_tga_header *header, const char *target)
{
	fprintf(stdout,
			"\nTGA HEADER (%s) =\n"
			"\tid_len = %hhd\n\tcm_type = %hhd\n\timg_type = %hhd"
			"\n\tcm_first_entry = %hu\n\tcm_length = %hu\n"
			"\tcm_bpp = %hhu\n\tx_origin = %hu\n\ty_origin = "
			"%hu\n\timage_width = %hu\n\timage_height = %hu\n"
			"\tbpp = %hhu\n\timage_descriptor_bits = %c%c%c%c%c%c%c%c\n\n",
			target,
			header->id_len,
			header->cm_type,
			header->img_type,
			header->cm_first_entry,
			header->cm_length,
			header->cm_bpp,
			header->x_origin,
			header->y_origin,
			header->image_width,
			header->image_heigth,
			header->bpp,
			BYTE_TO_BINARY(header->image_descriptor));

			sprintf(tga_info,
			"\tid_len = %hhd\n\tcm_type = %hhd\n\timg_type = %hhd"
			"\n\tcm_first_entry = %hu\n\tcm_length = %hu\n"
			"\tcm_bpp = %hhu\n\tx_origin = %hu\n\ty_origin = "
			"%hu\n\timage_width = %hu\n\timage_height = %hu\n"
			"\tbpp = %hhu\n\timage_descriptor_bits = %c%c%c%c%c%c%c%c\n",
			header->id_len,
			header->cm_type,
			header->img_type,
			header->cm_first_entry,
			header->cm_length,
			header->cm_bpp,
			header->x_origin,
			header->y_origin,
			header->image_width,
			header->image_heigth,
			header->bpp,
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

static bool tga_fill_info(t_tga *tga, void *data)
{
	if (tga && data)
	{
		tga->header = (t_tga_header *)data;
		tga->image_origin = tga_get_origin(tga->header->image_descriptor);
		tga->width = tga->header->image_width;
		tga->height = tga->header->image_heigth;
		tga->depth = tga->header->bpp;
		tga->signature = (char*)(data + tga->file_size - 18);
		if (tga->header->id_len > 0)
			tga->id = (char*)(data + sizeof(t_tga_header));
		if (strcmp(tga->signature, "TRUEVISION-XFILE.") == 0)
		{
			tga->extension_offset = *(char*)(data + tga->file_size - 26);
			tga->developer_offset = *(char*)(data + tga->file_size - 22);
		}
		tga->data_offset = sizeof(t_tga_header) + tga->header->id_len \
			+ tga->header->cm_length * (tga->header->cm_bpp / 8);
		return (true);
	}
	return (tga_berror("NULL pointers in tga_fill_info()!", NULL));
}

bool		tga_clean(t_tga *tga)
{
	if (tga)
	{
		if (tga->data)
			free(tga->data);
		if (tga->pixels)
			free(tga->pixels);
		tga->data = NULL;
		tga->pixels = NULL;
		free(tga);
		tga = NULL;
		return (true);
	}
	return (false);
}

t_tga 		*tga_load_file(const char *target)
{
	t_tga	*tga;

	tga = NULL;
	if (target)
	{
		if (!(tga = (t_tga*)malloc(sizeof(t_tga))))
			return (tga_error("Can't allocate memory for TGA file!", NULL));
		bzero((void*)tga, sizeof(t_tga));
		if (!(tga->data = tga_process_file(target, &tga->file_size)))
			return (tga_error("Could not read target file", tga));
		if (tga->file_size <= sizeof(t_tga_header))
			return (tga_error("Empty or corrupted TGA file", tga));
		if (!(tga_fill_info(tga, tga->data)))
			return (tga_error("Error during header decryption", tga));

		// DEBUGGING
		tga_print_header(tga->header, target);

		if (!(tga_process_pixels(tga)))
			return (tga_error("Failed processing TGA file's pixels!", tga));
		else
			return (tga);
	}
	return (tga_error("NULL target pointer in tga_load_file()!", tga));
}
