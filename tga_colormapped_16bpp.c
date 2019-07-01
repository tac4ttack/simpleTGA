/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_16bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:47 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga.h"

bool				tga_colormapped_16bpp_single(t_tga *tga, \
												const int dst, \
												const int src)
{
	unsigned char	*it;
	unsigned char	*cm;
	unsigned char	argb[4];

	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		cm = (unsigned char *)(tga->data + sizeof(t_tga_header) \
								+ tga->header->id_len);
		argb[0] = 0xFF - ((cm[(it[src] * (tga->header->cm_bpp >> 3)) + 1] \
						& 0x80) >> 7);
		argb[1] = (cm[(it[src] * (tga->header->cm_bpp >> 3)) + 1] \
					>> 2) & 0x1F;
		argb[2] = ((cm[(it[src] * (tga->header->cm_bpp >> 3)) + 1] << 3) \
					& 0x1C) | ((cm[(it[src] * (tga->header->cm_bpp >> 3))] \
					>> 5) & 0x07);
		argb[3] = cm[(it[src] * (tga->header->cm_bpp >> 3))] & 0x1F;
		argb[1] = (argb[1] << 3) | (argb[1] >> 2);
		argb[2] = (argb[2] << 3) | (argb[2] >> 2);
		argb[3] = (argb[3] << 3) | (argb[3] >> 2);
		tga->pixels[dst] = (argb[0] << 24) | (argb[1] << 16) \
						| (argb[2] << 8) | argb[3];
		return (true);
	}
	return (tga_berror("NULL parameter in CM16S!", tga));
}

static void			colormapped_16bpp_get_indexes(t_tga *tga, \
													unsigned char *ar[2])
{
	ar[0] = (unsigned char *)(tga->data + tga->data_offset);
	ar[1] = (unsigned char *)(tga->data + sizeof(t_tga_header) \
							+ tga->header->id_len);
}

static void			colormapped_16bpp_fill_channels(unsigned char *argb, \
													unsigned int *dst)
{
	argb[1] = (argb[1] << 3) | (argb[1] >> 2);
	argb[2] = (argb[2] << 3) | (argb[2] >> 2);
	argb[3] = (argb[3] << 3) | (argb[3] >> 2);
	*dst = (argb[0] << 24) | (argb[1] << 16) | (argb[2] << 8) | argb[3];
	dst++;
}

bool				tga_colormapped_16bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*ar[2];
	unsigned char	argb[4];

	i = 0;
	if (tga && !(*ar = NULL))
	{
		colormapped_16bpp_get_indexes(tga, ar);
		while (i < (tga->n_pix) * (tga->header->bpp >> 3))
		{
			argb[0] = 0xFF - ((ar[1][(ar[0][i] * (tga->header->cm_bpp >> 3)) \
															+ 1] & 0x80) >> 7);
			argb[1] = (ar[1][(ar[0][i] * (tga->header->cm_bpp >> 3)) + 1] \
						>> 2) & 0x1F;
			argb[2] = ((ar[1][(ar[0][i] * (tga->header->cm_bpp >> 3)) \
								+ 1] << 3) & 0x1C) | ((ar[1][(ar[0][i] * \
								(tga->header->cm_bpp >> 3))] >> 5) & 0x07);
			argb[3] = ar[1][(ar[0][i] * (tga->header->cm_bpp >> 3))] & 0x1F;
			colormapped_16bpp_fill_channels((unsigned char*)&argb, dst);
			i += (tga->header->bpp >> 3);
		}
		return (true);
	}
	return (tga_berror("NULL parameter in CM16!", tga));
}
