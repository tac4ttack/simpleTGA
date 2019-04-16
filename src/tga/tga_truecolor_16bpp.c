/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_16bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:48:00 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_truecolor_16bpp_single(t_tga *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	unsigned char	argb[4];
	if (dst == 0)
		fprintf(stdout, "debug -> tga_truecolor_16bpp_single()\n", NULL);
	it = (unsigned char *)(tga->data + tga->data_offset);
	argb[0] = 255 * ((it[src + 1] & 0x80) >> 7);
    argb[1] = (it[src + 1] >> 2) & 0x1F;
    argb[2] = ((it[src + 1] << 3) & 0x1C) | ((it[src] >> 5) & 0x07);
	argb[3] = (it[src] & 0x1F);
	argb[1] = (argb[1] << 3) | (argb[1] >> 2);
	argb[2] = (argb[2] << 3) | (argb[2] >> 2);
	argb[3] = (argb[3] << 3) | (argb[3] >> 2);
	pixels[dst] = (argb[0] << 24) + (argb[1] << 16) + (argb[2] << 8) | argb[3];
}

void				tga_truecolor_16bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	argb[4];
	fprintf(stdout, "debug -> tga_truecolor_16bpp())\n", NULL);
	i = 0;
	it = (unsigned char *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height * 2)
	{
        argb[0] = 255 * ((it[i + 1] & 0x80) >> 7);
        argb[1] = (it[i + 1] >> 2) & 0x1F;
        argb[2] = ((it[i + 1] << 3) & 0x1C) | ((it[i] >> 5) & 0x07);
        argb[3] = (it[i] & 0x1F);
		argb[1] = (argb[1] << 3) | (argb[1] >> 2);
        argb[2] = (argb[2] << 3) | (argb[2] >> 2);
        argb[3] = (argb[3] << 3) | (argb[3] >> 2);
		*pixels = (argb[0] << 24) | (argb[1] << 16) | (argb[2] << 8) | argb[3];
		i += 2;
		pixels++;
	}
}
