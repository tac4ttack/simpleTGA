/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_32bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga.h"

bool				tga_truecolor_32bpp_single(t_tga *tga, \
												const int dst, \
												const int src)
{
	unsigned char	*it;

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		tga->pixels[dst] = ((it[src + 3]) << 24) \
							| (it[src + 2] << 16) \
							| (it[src + 1] << 8) \
							| (it[src]);
		return (true);
	}
	return (tga_berror("NULL parameter in TC32S!", tga));
}

bool				tga_truecolor_32bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < (tga->n_pix) * 4)
		{
			dst[i / 4] = ((it[i + 3]) << 24) \
							| (it[i + 2] << 16) \
							| (it[i + 1] << 8) \
							| (it[i]);
			i += 4;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in TC32!", tga));
}
