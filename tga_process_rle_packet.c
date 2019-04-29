/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rle_packet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:43:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/29 14:40:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

static bool	rlecm_get_pixel(t_tga *tga, const int dst, const int src)
{
	if (tga)
	{
		if (tga->header->cm_bpp == 15)
			return (tga_truecolor_15bpp_single(tga, dst, src));
		else if (tga->header->cm_bpp == 16)
			return (tga_colormapped_16bpp_single(tga, dst, src));
		else if (tga->header->cm_bpp == 24)
			return (tga_truecolor_24bpp_single(tga, dst, src));
		else if (tga->header->cm_bpp == 32)
			return (tga_colormapped_32bpp_single(tga, dst, src));
		else
			return (tga_berror("Invalid pixel depth for CMRLE decoding!", tga));
	}
	return (tga_berror("NULL TGA pointer in rlecm_get_pixel()!", tga));
}

static bool	rletc_get_pixel(t_tga *tga, const int dst, const int src)
{
	if (tga)
	{
		if (tga->header->bpp == 15)
			return (tga_truecolor_15bpp_single(tga, dst, src));
		else if (tga->header->bpp == 16)
			return (tga_truecolor_16bpp_single(tga, dst, src));
		else if (tga->header->bpp == 24)
			return (tga_truecolor_24bpp_single(tga, dst, src));
		else if (tga->header->bpp == 32)
			return (tga_truecolor_32bpp_single(tga, dst, src));
		else
			return (tga_berror("Invalid pixel depth for TCRLE decoding!", tga));
	}
	return (tga_berror("NULL TGA pointer in rletc_get_pixel()!", tga));
}

static bool	rlebw_get_pixel(t_tga *tga, const int dst, const int src)
{
	if (tga)
	{
		if (tga->header->bpp == 8)
			return (tga_blackwhite_8bpp_single(tga, dst, src));
		else if (tga->header->bpp == 16)
			return (tga_blackwhite_16bpp_single(tga, dst, src));
		else
			return (tga_berror("Invalid pixel depth for BWRLE decoding!", tga));
	}
	return (tga_berror("NULL TGA pointer in rlebw_get_pixel()!", tga));
}

bool		tga_process_rle_packet(t_tga *tga, size_t cursor[3])
{
	while (cursor[2]--)
	{
		if (tga->header->img_type == 9)
			rlecm_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		else if (tga->header->img_type == 10)
			rletc_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		else if (tga->header->img_type == 11)
			rlebw_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		cursor[0]++;
	}
	cursor[1] += (tga->depth >> 3);
	return (true);
}

bool		tga_process_raw_packet(t_tga *tga, size_t cursor[3])
{
	while (cursor[2]--)
	{
		if (tga->header->img_type == 9)
			rlecm_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		else if (tga->header->img_type == 10)
			rletc_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		else if (tga->header->img_type == 11)
			rlebw_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		cursor[0]++;
		cursor[1] += (tga->depth >> 3);
	}
	return (true);
}
