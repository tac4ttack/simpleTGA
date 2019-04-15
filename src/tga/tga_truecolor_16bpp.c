/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_16bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/11 12:41:45 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_truecolor_16bpp_single(t_tga_info *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*iterator;
	unsigned char	comp[4];
	// fprintf(stdout, "debug -> tga_truecolor_16bpp_single()\n", NULL);
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	comp[0] = 255 * ((iterator[src + 1] & 0x80) >> 7);
    comp[1] = (iterator[src + 1] >> 2) & 0x1F;
    comp[2] = ((iterator[src + 1] << 3) & 0x1C) | ((iterator[src] >> 5) & 0x07);
	comp[3] = (iterator[src] & 0x1F);
	comp[1] = (comp[1] << 3) | (comp[1] >> 2);
	comp[2] = (comp[2] << 3) | (comp[2] >> 2);
	comp[3] = (comp[3] << 3) | (comp[3] >> 2);
	pixels[dst] = (comp[0] << 24) + (comp[1] << 16) + (comp[2] << 8) | comp[3];
}

void				tga_truecolor_16bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*iterator;
	unsigned char	comp[4];
	fprintf(stdout, "debug -> tga_truecolor_16bpp())\n", NULL);
	i = 0;
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height * 2)
	{
        comp[0] = 255 * ((iterator[i + 1] & 0x80) >> 7);
        comp[1] = (iterator[i + 1] >> 2) & 0x1F;
        comp[2] = ((iterator[i + 1] << 3) & 0x1C) | ((iterator[i] >> 5) & 0x07);
        comp[3] = (iterator[i] & 0x1F);
		comp[1] = (comp[1] << 3) | (comp[1] >> 2);
        comp[2] = (comp[2] << 3) | (comp[2] >> 2);
        comp[3] = (comp[3] << 3) | (comp[3] >> 2);
		*pixels = (comp[0] << 24) | (comp[1] << 16) | (comp[2] << 8) | comp[3];
		i += 2;
		pixels++;
	}
}
