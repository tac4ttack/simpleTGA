/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_32bpp.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 11:00:08 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/26 11:43:02 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

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
		while (i < (tga->width * tga->height) * (tga->header->bpp >> 3))
		{
			*dst = (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 3] << 24)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 2] << 16)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3)) + 1] << 8)
					| (cm[(it[i] * (tga->header->cm_bpp >> 3))]);

			if (i == 42)
			fprintf(stdout, "debug cm 32 -> %d | 0x%08x\n", it[i], cm[it[i]]);

			// *dst = cm[(it[i] * (tga->header->cm_bpp >> 3))];

			if (i == 42)
				fprintf(stdout, "debug cm 32 -> 0x%08x\n", *dst);

			i += (tga->header->bpp >> 3);
			dst++;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in CM32!", tga));
}
