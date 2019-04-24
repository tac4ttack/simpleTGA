/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rlebw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 13:06:16 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool	tga_process_rlebw(t_tga *tga)
{
	unsigned char	*iterator;
	size_t			cursors[3];

	if (tga)
	{
		if (tga->depth != 8)
			tga_error("Invalid pixel depth for RLE BW format!", tga);
		else
		{
			iterator = (unsigned char*)(tga->data + tga->data_offset);
			cursors[0] = 0;
			cursors[1] = 0;
			while (cursors[0] < tga->width * tga->height)
			{
				cursors[2] = (iterator[cursors[1]] & 0x7F) + 1;
				if ((iterator[cursors[1]++] & 0x80) == 0x80)
					{
						if (!(tga_process_rle_packet(tga, cursors)))
						return (tga_berror("Failed parsing RLE packet!", tga));
					}
				else
					{
						if (!(tga_process_raw_packet(tga, cursors)))
							return (tga_berror("Failed parsing RAW RLE packet!", tga));
					}
			}
			return (true);
		}
	}
	return (tga_berror("Parsing RLE BW format failed!", tga));
}
