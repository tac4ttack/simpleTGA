/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_16bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:47 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:15:53 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void				tga_colormapped_16bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;
	unsigned char	argb[4];
	fprintf(stdout, "debug -> tga_colormapped_16bpp()\n", NULL);
	i = 0;
	it = (unsigned char *)(tga->data + tga->data_offset);
	cm = (unsigned char *)(tga->data + sizeof(t_tga_header) + tga->header->id_len);
	while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
	{
		argb[0] = ((cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] & 0x80) >> 7) \
					* 255;
		argb[1] = (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] >> 2) & 0x1F;
		argb[2] = ((cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 3) & 0x1C) \
					| ((cm[(it[i] * (tga->header->cm_bpp >> 3))] >> 5) & 0x07);
		argb[3] = cm[(it[i] * (tga->header->cm_bpp >> 3))] & 0x1F;
		argb[1] = (argb[1] << 3) | (argb[1] >> 2);
        argb[2] = (argb[2] << 3) | (argb[2] >> 2);
        argb[3] = (argb[3] << 3) | (argb[3] >> 2);
		*pixels = (argb[0] << 24) | (argb[1] << 16) | (argb[2] << 8) | argb[3];
		i += (tga->header->bpp >> 3);
		pixels++;
	}
}

