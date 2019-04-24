/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_24bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 13:06:16 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool 				tga_truecolor_24bpp_single(t_tga *tga,
												const int dst, \
												const int src)
{
	unsigned char	*it;

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

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < tga->width * tga->height * 3)
		{
			tga->pixels[i / 3] = ((0xff << 24) \
						+ (it[i + 2] << 16) \
						+ (it[i + 1] << 8) \
						+ (it[i]));
			i += 3;
		}
		return (true);
	}
		return (tga_berror("NULL TGA pointer in TC24!", tga));
}
