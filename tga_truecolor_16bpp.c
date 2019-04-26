/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_16bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/26 11:18:45 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_truecolor_16bpp_single(t_tga *tga, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	unsigned char	argb[4];

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		argb[0] = 255 - ((it[src + 1] & 0x80) >> 7);
		argb[1] = (it[src + 1] >> 2) & 0x1F;
		argb[2] = ((it[src + 1] << 3) & 0x1C) | ((it[src] >> 5) & 0x07);
		argb[3] = (it[src] & 0x1F);
		argb[1] = (argb[1] << 3) | (argb[1] >> 2);
		argb[2] = (argb[2] << 3) | (argb[2] >> 2);
		argb[3] = (argb[3] << 3) | (argb[3] >> 2);
		tga->pixels[dst] = (argb[0] << 24) | (argb[1] << 16) \
							| (argb[2] << 8) | argb[3];
		return (true);
	}
	return (tga_berror("NULL parameter in TC16S!", tga));
}

bool				tga_truecolor_16bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	argb[4];

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < tga->width * tga->height * 2)
		{
			argb[0] = 255 - ((it[i + 1] & 0x80) >> 7);
			argb[1] = (it[i + 1] >> 2) & 0x1F;
			argb[2] = ((it[i + 1] << 3) & 0x1C) | ((it[i] >> 5) & 0x07);
			argb[3] = (it[i] & 0x1F);
			argb[1] = (argb[1] << 3) | (argb[1] >> 2);
			argb[2] = (argb[2] << 3) | (argb[2] >> 2);
			argb[3] = (argb[3] << 3) | (argb[3] >> 2);
			dst[i / 2] = (argb[0] << 24) | (argb[1] << 16) \
						| (argb[2] << 8) | argb[3];
			i += 2;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in TC16!", tga));
}
