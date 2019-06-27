/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_blackwhite_16bpp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 11:47:11 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/27 18:42:21 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_blackwhite_16bpp_single(t_tga *tga, \
												const int dst, \
												const int src)
{
	unsigned char	*it;

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		tga->pixels[dst] = ((it[src + 1] & 0xFF) << 24)  \
					| ((it[src] & 0xFF) << 16) \
					| ((it[src] & 0xFF) << 8)
					| ((it[src] & 0xFF));
		return (true);
	}
	return (tga_berror("NULL parameter in BW16S!", tga));
}

bool				tga_blackwhite_16bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < (tga->n_pix) * 2)
		{
			dst[i / 2] = (((it[i + 1] & 0xFF)) << 24)  \
						| ((it[i] & 0xFF) << 16) \
						| ((it[i] & 0xFF) << 8)
						| ((it[i] & 0xFF));
			i += 2;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in BW16!", tga));
}
