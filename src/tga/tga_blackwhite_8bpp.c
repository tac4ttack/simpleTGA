/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_blackwhite_8bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:21:32 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/11 14:57:11 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_blackwhite_8bpp_single(t_tga_info *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*iterator;

	iterator = (unsigned char *)(tga->data + tga->data_offset);
	pixels[dst] = ((0xFF) << 24)  \
				| ((iterator[src] & 0xFF) << 16) \
				| ((iterator[src] & 0xFF) << 8)
				| ((iterator[src] & 0xFF));
}

void 				tga_blackwhite_8bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*iterator;
	fprintf(stdout, "debug -> tga_truecolor_8bpp()\n", NULL);
	i = 0;
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height)
	{
		pixels[i] = ((0xFF) << 24)  \
					| ((iterator[i] & 0xFF) << 16) \
					| ((iterator[i] & 0xFF) << 8)
					| ((iterator[i] & 0xFF));
		i++;
	}
}
