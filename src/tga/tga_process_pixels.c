/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:19 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/10 17:50:01 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void tga_process_8bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t i;
	unsigned char *iterator;
	fprintf(stdout, "debug 8bpp!\n", NULL);
	i = 0;
	iterator = (unsigned char *)(tga->data + sizeof(t_tga_header));
	while (i < tga->width * tga->height)
	{

		*pixels = (((iterator[i] >> 6) & 0xFF) << 24) \
				+ (((iterator[i] >> 4) & 0xFF) << 16) \
				+ (((iterator[i] >> 2) & 0xFF) << 8) \
				+ (0xff << 24);
		// if (i % 3 == 0 && i < 10)
			// fprintf(stdout, "debug i = %zu | iterator = " BYTE_TO_BINARY_PATTERN "  | pixel = %#010x \n", i, BYTE_TO_BINARY(iterator[i]), *pixels);
		pixels++;
		i++;
	}
}
static int is_valid_bpp(const size_t depth, const int mod)
{
	if (mod == 1 || mod == 9)
	{
		if (depth == 8 || depth == 15 || depth == 16)
			return (1);
		else
			return (0);
	}
	else if (mod == 2 || mod == 10)
	{
		if (depth == 15 || depth == 16 || depth == 24 || depth == 32)
			return (1);
		else
			return (0);
	}
	else if (mod == 3 || mod == 11)
	{
		if (depth == 8)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static void tga_process_dispatch_raw(t_tga_info *tga, unsigned int *pix_data)
{
	if (tga && pix_data)
	{
		if (tga->header->img_type == 1 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rawcm(tga, pix_data);
		else if (tga->header->img_type == 2 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rawtc(tga, pix_data);
		else if (tga->header->img_type == 3 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rawbw(tga, pix_data);
		else
			tga_error("Invalid pixel depth for RAW format!", pix_data);
	}
}

static void tga_process_dispatch_rle(t_tga_info *tga, unsigned int *pix_data)
{
	if (tga && pix_data)
	{
		if (tga->header->img_type == 9 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rlecm(tga, pix_data);
		else if (tga->header->img_type == 10 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rletc(tga, pix_data);
		else if (tga->header->img_type == 11 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rlebw(tga, pix_data);
		else
			tga_error("Invalid pixel depth for RLE format!", pix_data);
	}
}

unsigned int		*tga_process_pixels(t_tga_info *tga)
{
	unsigned int	*pix_data;

	pix_data = NULL;
	if (!(pix_data = malloc(tga->width * tga->height * sizeof(unsigned int))))
		return (tga_error("Failed to allocate for pixels data!", tga->data));
	if (tga)
	{
		if (tga->header->img_type == 1 || tga->header->img_type == 2 \
				|| tga->header->img_type == 3)
			tga_process_dispatch_raw(tga, pix_data);
		else if (tga->header->img_type == 9 || tga->header->img_type == 10 \
				|| tga->header->img_type == 11)
			tga_process_dispatch_rle(tga, pix_data);
		else
		{
			free(pix_data);
			return (tga_error("TGA file format type is invalid!", tga->data));
		}
		if (!pix_data)
			return (tga_error("Failed to retrieve pixels data!", tga->data));
		return (pix_data);
	}
	else
		return (tga_error("NULL TGA pointer in process_pixels() !", tga->data));
}
