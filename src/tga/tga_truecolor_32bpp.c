/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_32bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/15 11:38:52 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void 				tga_truecolor_32bpp_single(t_tga_info *tga, \
												unsigned int *pixels, \
												const int dst, \
												const int src)
{
	unsigned char	*iterator;
	// fprintf(stdout, "debug -> tga_truecolor_32bpp_single()\n", NULL);
	iterator = (unsigned char *)(tga->data + tga->data_offset);
	pixels[dst] = ((iterator[src + 3] << 24) \
					| (iterator[src + 2] << 16) \
					| (iterator[src + 1] << 8) \
					| (iterator[src]));
}

void 				tga_truecolor_32bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned int	*iterator;
	fprintf(stdout, "debug -> tga_truecolor_32bpp()\n", NULL);
	i = 0;
	iterator = (unsigned int *)(tga->data + tga->data_offset);
	while (i < tga->width * tga->height)
	{
		pixels[i] = iterator[i];
		i++;
	}
}
