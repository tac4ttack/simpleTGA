/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_truecolor_24bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:38:07 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/29 17:40:38 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_truecolor_24bpp_single(t_tga *tga,
												const int dst, \
												const int src)
{
	unsigned char	*it;

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		tga->pixels[dst] = ((0xFF << 24) \
							| (it[src + 2] << 16) \
							| (it[src + 1] << 8) \
							| (it[src]));
		return (true);
	}
	return (tga_berror("NULL parameter in TC24S!", tga));
}

bool				tga_truecolor_24bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < tga->n_pix * 3)
		{
			dst[i / 3] = ((0xFF << 24) \
						| (it[i + 2] << 16) \
						| (it[i + 1] << 8) \
						| (it[i]));
			i += 3;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in TC24!", tga));
}
