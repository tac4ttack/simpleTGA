/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rle_packet.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 09:43:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:06:12 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

static void				rletc_get_pixel(t_tga *tga, \
										unsigned int *pixels, \
										const int dst, \
										const int src)
{
	if (tga && pixels)
	{
		if (tga->depth == 15)
			tga_truecolor_15bpp_single(tga, pixels, dst, src);
		else if (tga->depth == 16)
			tga_truecolor_16bpp_single(tga, pixels, dst, src);
		else if (tga->depth == 24)
			tga_truecolor_24bpp_single(tga, pixels, dst, src);
		else if (tga->depth == 32)
			tga_truecolor_32bpp_single(tga, pixels, dst, src);
	}
}

void					tga_process_rle_packet(t_tga *tga, \
												unsigned int *pixels, \
												size_t cursors[3])
{
	while (cursors[2]--)
	{
		if (tga->header->img_type == 9)
			;// rlemc_get_pixel(tga, pixels, (int)cursors[0], (int)cursors[1]); // CM
		else if (tga->header->img_type == 10)
			rletc_get_pixel(tga, pixels, (int)cursors[0], (int)cursors[1]);
		else if (tga->header->img_type == 11)
			tga_blackwhite_8bpp_single(tga, pixels, \
										(int)cursors[0], (int)cursors[1]);
		cursors[0]++;
	}
	cursors[1] += tga->depth >> 3;
}

void					tga_process_raw_packet(t_tga *tga, \
												unsigned int *pixels, \
												size_t cursors[3])
{
	while (cursors[2]--)
	{
		if (tga->header->img_type == 9)
			; // CM
		else if (tga->header->img_type == 10)
			rletc_get_pixel(tga, pixels, (int)cursors[0], (int)cursors[1]);
		else if (tga->header->img_type == 11)
			tga_blackwhite_8bpp_single(tga, pixels, \
										(int)cursors[0], (int)cursors[1]);
		cursors[0]++;
		cursors[1] += tga->depth >> 3;
	}
}
