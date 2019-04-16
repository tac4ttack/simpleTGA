/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_8bpp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:47 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:46:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void				tga_colormapped_8bpp(t_tga *tga, unsigned int *pixels)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;
	fprintf(stdout, "debug -> tga_colormapped_8bpp()\n", NULL);
	i = 0;
	it = (unsigned char *)(tga->data + tga->data_offset);
	cm = (unsigned char *)(tga->data + sizeof(t_tga_header) + tga->header->id_len);
	while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
	{
		*pixels = (0xff << 24)
				| ((cm[(it[i] * (tga->header->cm_bpp >> 3))]) & 0xFF << 16)
				| ((cm[(it[i] * (tga->header->cm_bpp >> 3))]) & 0xFF << 8)
				| ((cm[(it[i] * (tga->header->cm_bpp >> 3))]) & 0xFF);
		i += (tga->header->bpp >> 3);
		pixels++;
	}
}

