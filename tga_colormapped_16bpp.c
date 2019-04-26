/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_16bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:47 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/26 11:19:39 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_colormapped_16bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;
	unsigned char	argb[4];

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		cm = (unsigned char *)(tga->data + sizeof(t_tga_header) \
								+ tga->header->id_len);
		while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
		{
			argb[0] = ((cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] & 0x80) \
						>> 7) * 255;
			argb[1] = (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] \
						>> 2) & 0x1F;
			argb[2] = ((cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 3) \
						& 0x1C) | ((cm[(it[i] * (tga->header->cm_bpp >> 3))] \
						>> 5) & 0x07);
			argb[3] = cm[(it[i] * (tga->header->cm_bpp >> 3))] & 0x1F;
			argb[1] = (argb[1] << 3) | (argb[1] >> 2);
			argb[2] = (argb[2] << 3) | (argb[2] >> 2);
			argb[3] = (argb[3] << 3) | (argb[3] >> 2);
			*dst = (argb[0] << 24) | (argb[1] << 16) \
							| (argb[2] << 8) | argb[3];
			i += (tga->header->bpp >> 3);
			dst++;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in CM16!", tga));
}

