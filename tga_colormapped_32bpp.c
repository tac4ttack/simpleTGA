/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_32bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:00:08 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga.h"

bool				tga_colormapped_32bpp_single(t_tga *tga, \
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
		tga->pixels[dst] =\
				(cm[(it[src] * (tga->header->cm_bpp >> 3)) + 3] << 24)
				| (cm[(it[src] * (tga->header->cm_bpp >> 3)) + 2] << 16)
				| (cm[(it[src] * (tga->header->cm_bpp >> 3)) + 1] << 8)
				| (cm[(it[src] * (tga->header->cm_bpp >> 3))]);
		return (true);
	}
	return (tga_berror("NULL parameter in CM32S!", tga));
}

bool				tga_colormapped_32bpp(t_tga *tga, unsigned int *dst)
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
		while (i < (tga->n_pix) * (tga->header->bpp >> 3))
		{
			*dst = (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 3] << 24)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 2] << 16)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 8)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3))]);
			i += (tga->header->bpp >> 3);
			dst++;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in CM32!", tga));
}
