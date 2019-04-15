/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rlebw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/11 14:56:22 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rlebw(t_tga_info *tga, unsigned int *pix_data)
{
	unsigned char	*iterator;
	size_t			cursors[3];

	if (tga && pix_data)
	{
		if (tga->depth != 8)
			tga_error("Invalid pixel depth for RLE BW format!", pix_data);
		else
		{
			iterator = (unsigned char*)(tga->data + tga->data_offset);
			cursors[0] = 0;
			cursors[1] = 0;
			while (cursors[0] < tga->width * tga->height)
			{
				cursors[2] = (iterator[cursors[1]] & 0x7F) + 1;
				if ((iterator[cursors[1]++] & 0x80) == 0x80)
					tga_process_rle_packet(tga, pix_data, cursors);
				else
					tga_process_raw_packet(tga, pix_data, cursors);
			}
		}
	}
}
