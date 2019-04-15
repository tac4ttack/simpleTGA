/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_24bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/11 14:40:10 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_truecolor_24bpp_single(t_tga_info *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*iterator;
	// fprintf(stdout, "debug -> tga_truecolor_24bpp_single()\n", NULL);
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	pixels[dst] = ((0xff << 24) \
				+ (iterator[src + 2] << 16) \
				+ (iterator[src + 1] << 8) \
				+ (iterator[src]));
}

void				tga_truecolor_24bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*iterator;
	fprintf(stdout, "debug -> tga_truecolor_24bpp()\n", NULL);
	i = 0;
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height * 3)
	{
		*pixels = ((0xff << 24) \
					+ (iterator[i + 2] << 16) \
					+ (iterator[i + 1] << 8) \
					+ (iterator[i]));
		i += 3;
		pixels++;
	}
}
