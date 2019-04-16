/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_24bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 18:10:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

bool 				tga_truecolor_24bpp_single(t_tga *tga,
												const int dst, \
												const int src)
{
	unsigned char	*it;

	if (dst == 0)
		fprintf(stdout, "debug -> tga_truecolor_24bpp_single()\n", NULL);

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		tga->pixels[dst] = ((0xff << 24) \
					+ (it[src + 2] << 16) \
					+ (it[src + 1] << 8) \
					+ (it[src]));
		return (true);
	}
		return (tga_berror("NULL TGA pointer in TC24S!", tga));
}

bool				tga_truecolor_24bpp(t_tga *tga)
{
	size_t			i;
	unsigned char	*it;
	fprintf(stdout, "debug -> tga_truecolor_24bpp()\n", NULL);
	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < tga->width * tga->height * 3)
		{
			*tga->pixels = ((0xff << 24) \
						+ (it[i + 2] << 16) \
						+ (it[i + 1] << 8) \
						+ (it[i]));
			i += 3;
			tga->pixels++;
		}
		return (true);
	}
		return (tga_berror("NULL TGA pointer in TC24!", tga));
}
