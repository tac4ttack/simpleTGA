/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rle_packet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:43:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 18:06:07 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

static bool	rletc_get_pixel(t_tga *tga, const int dst, const int src)
{
	if (tga)
	{
		if (tga->depth == 15)
			return (tga_truecolor_15bpp_single(tga, dst, src));
		else if (tga->depth == 16)
			return (tga_truecolor_16bpp_single(tga, dst, src));
		else if (tga->depth == 24)
			return (tga_truecolor_24bpp_single(tga, dst, src));
		else if (tga->depth == 32)
			return (tga_truecolor_32bpp_single(tga, dst, src));
		else
			return (tga_berror("Invalid pixel depth for RLE decoding!", tga));
	}
	return (tga_berror("NULL TGA pointer in rle_tc_get_pixel()!", tga));
}

bool		tga_process_rle_packet(t_tga *tga, size_t cursor[3])
{
	while (cursor[2]--)
	{
		if (tga->header->img_type == 9)
			;// rlemc_get_pixel(tga, pixels, (int)cursor[0], (int)cursor[1]); // CM
		else if (tga->header->img_type == 10)
			rletc_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		else if (tga->header->img_type == 11)
			tga_blackwhite_8bpp_single(tga, (int)cursor[0], (int)cursor[1]);
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
			; // CM
		else if (tga->header->img_type == 10)
			rletc_get_pixel(tga, (int)cursor[0], (int)cursor[1]);
		else if (tga->header->img_type == 11)
			tga_blackwhite_8bpp_single(tga, (int)cursor[0], (int)cursor[1]);
		cursor[0]++;
		cursor[1] += (tga->depth >> 3);
	}
	return (true);
}
