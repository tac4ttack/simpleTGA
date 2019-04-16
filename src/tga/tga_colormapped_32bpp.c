/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_32bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:00:08 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 17:54:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

bool				tga_colormapped_32bpp(t_tga *tga)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;

	fprintf(stdout, "debug -> tga_colormapped_32bpp()\n", NULL);

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		cm = (unsigned char *)(tga->data \
									+ sizeof(t_tga_header) \
									+ tga->header->id_len);
		while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
		{
			*tga->pixels = (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 3] << 24)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 2] << 16)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 8)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3))]);
			i += (tga->header->bpp >> 3);
			tga->pixels++;
		}
		return (true);
	}
	return (tga_berror("NULL TGA pointer in CM32!", tga));
}
