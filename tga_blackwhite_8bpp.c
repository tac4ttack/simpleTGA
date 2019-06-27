/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_blackwhite_8bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:21:32 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/27 18:42:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_blackwhite_8bpp_single(t_tga *tga, \
												const int dst, \
												const int src)
{
	unsigned char	*it;

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		tga->pixels[dst] = ((0xFF) << 24)  \
					| ((it[src] & 0xFF) << 16) \
					| ((it[src] & 0xFF) << 8)
					| ((it[src] & 0xFF));
		return (true);
	}
	return (tga_berror("NULL parameter in BW8S!", tga));
}

bool				tga_blackwhite_8bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < tga->n_pix)
		{
			dst[i] = ((0xFF) << 24)  \
						| ((it[i] & 0xFF) << 16) \
						| ((it[i] & 0xFF) << 8)
						| ((it[i] & 0xFF));
			i++;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in BW8!", tga));
}
