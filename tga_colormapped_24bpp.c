/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_24bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:27:38 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/29 15:57:01 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_colormapped_24bpp_single(t_tga *tga, \
													const int dst, \
													const int src)
{
	unsigned char	*it;
	unsigned char	*cm;

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		cm = (unsigned char *)(tga->data \
									+ sizeof(t_tga_header) \
									+ tga->header->id_len);
		tga->pixels[dst] = (0xFF << 24)
				| (cm[(it[src] * (tga->header->cm_bpp >> 3)) + 2] << 16)
				| (cm[(it[src] * (tga->header->cm_bpp >> 3)) + 1] << 8)
				| (cm[(it[src] * (tga->header->cm_bpp >> 3))]);
		return (true);
	}
	return (tga_berror("NULL parameter in CM24S!", tga));
}

bool				tga_colormapped_24bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		cm = (unsigned char *)(tga->data \
									+ sizeof(t_tga_header) \
									+ tga->header->id_len);
		while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
		{
			*dst = (0xFF << 24)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 2] << 16)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 8)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3))]);
			i += (tga->header->bpp >> 3);
			dst++;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in CM24!", tga));
}
