/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:19 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:58:21 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

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
		if (depth == 8 || depth == 16)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

static void tga_process_dispatch_raw(t_tga *tga, unsigned int *pixels)
{
	if (tga && pixels)
	{
		if (tga->header->img_type == 1 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rawcm(tga, pixels);
		else if (tga->header->img_type == 2 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rawtc(tga, pixels);
		else if (tga->header->img_type == 3 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rawbw(tga, pixels);
		else
			tga_error("Invalid pixel depth for RAW format!", pixels);
	}
}

static void tga_process_dispatch_rle(t_tga *tga, unsigned int *pixels)
{
	if (tga && pixels)
	{
		if (tga->header->img_type == 9 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rlecm(tga, pixels);
		else if (tga->header->img_type == 10 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rletc(tga, pixels);
		else if (tga->header->img_type == 11 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			tga_process_rlebw(tga, pixels);
		else
			tga_error("Invalid pixel depth for RLE format!", pixels);
	}
}

unsigned int		*tga_process_pixels(t_tga *tga)
{
	unsigned int	*pixels;

	pixels = NULL;
	if (!(pixels = malloc(tga->width * tga->height * sizeof(unsigned int))))
		return (tga_error("Failed to allocate for pixels data!", tga->data));
	if (tga)
	{
		if (tga->header->img_type == 1 || tga->header->img_type == 2 \
				|| tga->header->img_type == 3)
			tga_process_dispatch_raw(tga, pixels);
		else if (tga->header->img_type == 9 || tga->header->img_type == 10 \
				|| tga->header->img_type == 11)
			tga_process_dispatch_rle(tga, pixels);
		else
		{
			free(pixels);
			return (tga_error("TGA file format type is invalid!", tga->data));
		}
		if (!pixels)
			return (tga_error("Failed to retrieve pixels data!", tga->data));
		return (pixels);
	}
	else
		return (tga_error("NULL TGA pointer in process_pixels() !", tga->data));
}
