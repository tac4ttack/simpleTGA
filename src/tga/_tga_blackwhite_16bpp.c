/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tga_blackwhite_16bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:21:32 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/18 10:05:18 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"


 // OBOSOLETTEEEEE! SE BASER  SUR LES NOUVELLES VERSIONS RETOURNANT DES BOOLS!!!

void 				tga_blackwhite_16bpp_single(t_tga *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	if (dst == 0)
		POP("tga_truecolor_8bpp_single()");
	it = (unsigned char *)(tga->data + tga->data_offset);
	pixels[dst] = ((0xFF) << 24)  \
				| ((it[src] & 0xFF) << 16) \
				| ((it[src] & 0xFF) << 8)
				| ((it[src] & 0xFF));
}

void 				tga_blackwhite_16bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	POP("tga_truecolor_8bpp()");
	i = 0;
	it = (unsigned char *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height)
	{
		pixels[i] = ((0xFF) << 24)  \
					| ((it[i] & 0xFF) << 16) \
					| ((it[i] & 0xFF) << 8)
					| ((it[i] & 0xFF));
		i++;
	}
}
