/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:19 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/18 10:14:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

static bool is_valid_bpp(const size_t depth, const int mod)
{
	if (mod == 1 || mod == 9)
	{
		if (depth == 8 || depth == 15 || depth == 16)
			return (true);
		else
			return (tga_berror("Invalid BPP for current image type!", NULL));
	}
	else if (mod == 2 || mod == 10)
	{
		if (depth == 15 || depth == 16 || depth == 24 || depth == 32)
			return (true);
		else
			return (tga_berror("Invalid BPP for current image type!", NULL));
	}
	else if (mod == 3 || mod == 11)
	{
		if (depth == 8 || depth == 16)
			return (true);
		else
			return (tga_berror("Invalid BPP for current image type!", NULL));
	}
	else
		return (tga_berror("Invalid BPP for current image type!", NULL));
}

static bool tga_process_dispatch_raw(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->img_type == 1 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			return (tga_process_rawcm(tga));
		else if (tga->header->img_type == 2 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			return (tga_process_rawtc(tga));
		else if (tga->header->img_type == 3 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			return (tga_process_rawbw(tga));
		else
			return (tga_berror("Invalid pixel depth for RAW format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_dispatch_raw()!", tga));
}

static bool tga_process_dispatch_rle(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->img_type == 9 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			return (tga_process_rlecm(tga));
		else if (tga->header->img_type == 10 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			return (tga_process_rletc(tga));
		else if (tga->header->img_type == 11 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->depth, tga->header->img_type))
			return (tga_process_rlebw(tga));
		else
			return (tga_berror("Invalid pixel depth for RLE format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_dispatch_rle()!", tga));

}

bool	tga_process_pixels(t_tga *tga)
{
	if (tga)
	{
		if (!(tga->pixels = (unsigned int *)malloc(tga->width * tga->height * sizeof(unsigned int))))
			return (tga_berror("Failed to allocate for pixels data!", tga));
		bzero((void*)tga->pixels, tga->width * tga->height * sizeof(unsigned int));
		if (tga->header->img_type == 1 || tga->header->img_type == 2 \
				|| tga->header->img_type == 3)
			return (tga_process_dispatch_raw(tga));
		else if (tga->header->img_type == 9 || tga->header->img_type == 10 \
				|| tga->header->img_type == 11)
			return (tga_process_dispatch_rle(tga));
		else
			return (tga_berror("TGA file format type is invalid!", tga));
	}
	else
		return (tga_berror("NULL TGA pointer in tga_process_pixels()!", tga));
}
