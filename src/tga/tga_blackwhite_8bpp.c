/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_blackwhite_8bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:21:32 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:48:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_blackwhite_8bpp_single(t_tga *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	if (dst == 0)
		fprintf(stdout, "debug -> tga_truecolor_8bpp_single()\n", NULL);
	it = (unsigned char *)(tga->data + tga->data_offset);
	pixels[dst] = ((0xFF) << 24)  \
				| ((it[src] & 0xFF) << 16) \
				| ((it[src] & 0xFF) << 8)
				| ((it[src] & 0xFF));
}

void 				tga_blackwhite_8bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	fprintf(stdout, "debug -> tga_truecolor_8bpp()\n", NULL);
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
