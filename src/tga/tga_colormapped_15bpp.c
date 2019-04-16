/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_15bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:47 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:21:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void				tga_colormapped_15bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;
	unsigned char	rgb[3];
	fprintf(stdout, "debug -> tga_colormapped_15bpp()\n", NULL);
	i = 0;
	it = (unsigned char *)(tga->data + tga->data_offset);
	cm = (unsigned char *)(tga->data + sizeof(t_tga_header) + tga->header->id_len);
	while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
	{
		rgb[0] = (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] >> 2) & 0x1F;
		rgb[1] = ((cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 3) & 0x1C) \
					| ((cm[(it[i] * (tga->header->cm_bpp >> 3))] >> 5) & 0x07);
		rgb[2] = (cm[(it[i] * (tga->header->cm_bpp >> 3))] & 0x1F);
		*pixels = (255 << 24) | (rgb[0] << 16) | (rgb[1] << 8) | rgb[2];
		i += (tga->header->bpp >> 3);
		pixels++;
	}
}

