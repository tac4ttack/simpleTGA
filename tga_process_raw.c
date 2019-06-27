/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_raw.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 10:36:05 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/27 18:49:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

static bool		is_valid_bpp(const size_t depth, const int mod)
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

static bool		tga_process_rawcm(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->cm_bpp == 8)
			return (tga_colormapped_8bpp(tga, tga->pixels));
		else if (tga->header->cm_bpp == 15)
			return (tga_colormapped_15bpp(tga, tga->pixels));
		else if (tga->header->cm_bpp == 16)
			return (tga_colormapped_16bpp(tga, tga->pixels));
		else if (tga->header->cm_bpp == 24)
			return (tga_colormapped_24bpp(tga, tga->pixels));
		else if (tga->header->cm_bpp == 32)
			return (tga_colormapped_32bpp(tga, tga->pixels));
		else
			return (tga_berror("Invalid pixel depth for RAW CM format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_rawcm()!", tga));
}

static bool		tga_process_rawtc(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->bpp == 15)
			return (tga_truecolor_15bpp(tga, tga->pixels));
		else if (tga->header->bpp == 16)
			return (tga_truecolor_16bpp(tga, tga->pixels));
		else if (tga->header->bpp == 24)
			return (tga_truecolor_24bpp(tga, tga->pixels));
		else if (tga->header->bpp == 32)
			return (tga_truecolor_32bpp(tga, tga->pixels));
		else
			return (tga_berror("Invalid pixel depth for RAW TC format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_rawtc()!", tga));
}

static bool		tga_process_rawbw(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->bpp == 8)
			return (tga_blackwhite_8bpp(tga, tga->pixels));
		else if (tga->header->bpp == 16)
			return (tga_blackwhite_16bpp(tga, tga->pixels));
		else
			return (tga_berror("Invalid pixel depth for RAW BW format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_rawbw()!", tga));
}

bool			tga_process_raw(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->img_type == 1 && tga->header->cm_type == 1 \
				&& is_valid_bpp(tga->header->bpp, tga->header->img_type))
			return (tga_process_rawcm(tga));
		else if (tga->header->img_type == 2 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->header->bpp, tga->header->img_type))
			return (tga_process_rawtc(tga));
		else if (tga->header->img_type == 3 && tga->header->cm_type == 0 \
				&& is_valid_bpp(tga->header->bpp, tga->header->img_type))
			return (tga_process_rawbw(tga));
		else
			return (tga_berror("Failed processing RAW image data!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_raw()!", tga));
}
