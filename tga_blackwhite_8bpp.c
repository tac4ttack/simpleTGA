/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_blackwhite_8bpp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:21:32 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 11:53:32 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

bool 				tga_blackwhite_8bpp_single(t_tga *tga, \
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
	return (tga_berror("NULL TGA pointer in BW8S!", tga));
}

bool 				tga_blackwhite_8bpp(t_tga *tga)
{
	size_t			i;
	unsigned char	*it;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		while (i < tga->width * tga->height)
		{
			tga->pixels[i] = ((0xFF) << 24)  \
						| ((it[i] & 0xFF) << 16) \
						| ((it[i] & 0xFF) << 8)
						| ((it[i] & 0xFF));
			i++;
		}
		return (true);
	}
	return (tga_berror("NULL TGA pointer in BW8!", tga));
}
