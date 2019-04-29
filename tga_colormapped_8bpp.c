/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_colormapped_8bpp.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:54:47 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/29 17:40:38 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool				tga_colormapped_8bpp(t_tga *tga, unsigned int *dst)
{
	size_t			i;
	unsigned char	*it;
	unsigned char	*cm;

	i = 0;
	if (tga)
	{
		it = (unsigned char *)(tga->data + tga->data_offset);
		cm = (unsigned char *)(tga->data + sizeof(t_tga_header) + tga->header->id_len);
		while (i < (tga->n_pix) * (tga->header->bpp >> 3))
		{
			*dst = (0xFF << 24)
					| ((cm[(it[i] * (tga->header->cm_bpp >> 3))]) & 0xFF << 16)
					| ((cm[(it[i] * (tga->header->cm_bpp >> 3))]) & 0xFF << 8)
					| ((cm[(it[i] * (tga->header->cm_bpp >> 3))]) & 0xFF);
			i += (tga->header->bpp >> 3);
			dst++;
		}
		return (true);
	}
	return (tga_berror("NULL parameter in CM8!", tga));
}

