/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_15bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:47:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_truecolor_15bpp_single(t_tga *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	unsigned char	rgb[3];
	if (dst == 0)
		fprintf(stdout, "debug -> tga_truecolor_15bpp_single()\n", NULL);
	it = (unsigned char *)(tga->data + tga->data_offset);
	rgb[0] = (it[src + 1] >> 2) & 0x1F;
	rgb[1] = ((it[src + 1] << 3) & 0x1C) | ((it[src] >> 5) & 0x07);
	rgb[2] = (it[src] & 0x1F);
	rgb[0] = (rgb[0] << 3) | (rgb[0] >> 2);
	rgb[1] = (rgb[1] << 3) | (rgb[1] >> 2);
	rgb[2] = (rgb[2] << 3) | (rgb[2] >> 2);
	pixels[dst] = (255 << 24) + (rgb[0] << 16) + (rgb[1] << 8) + rgb[2];
}

void				tga_truecolor_15bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	rgb[3];
	fprintf(stdout, "debug -> tga_truecolor_15bpp()\n", NULL);
	i = 0;
	it = (unsigned char *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height * 2)
	{
        rgb[0] = (it[i + 1] >> 2) & 0x1F;
        rgb[1] = ((it[i + 1] << 3) & 0x1C) | ((it[i] >> 5) & 0x07);
        rgb[2] = (it[i] & 0x1F);
		rgb[0] = (rgb[0] << 3) | (rgb[0] >> 2);
        rgb[1] = (rgb[1] << 3) | (rgb[1] >> 2);
        rgb[2] = (rgb[2] << 3) | (rgb[2] >> 2);
		*pixels = (255 << 24) | (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		i += 2;
		pixels++;
	}
}
