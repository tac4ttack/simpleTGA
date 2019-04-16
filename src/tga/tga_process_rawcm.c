/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawcm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:05:56 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rawcm(t_tga *tga, unsigned int *pixels)
{
	if (tga && pixels)
	{
		if (tga->header->cm_bpp == 8)
			tga_colormapped_8bpp(tga, pixels);
		else if (tga->header->cm_bpp == 15)
			tga_colormapped_15bpp(tga, pixels);
		else if (tga->header->cm_bpp == 16)
			tga_colormapped_16bpp(tga, pixels);
		else if (tga->header->cm_bpp == 24)
			tga_colormapped_24bpp(tga, pixels);
		else if (tga->header->cm_bpp == 32)
			tga_colormapped_32bpp(tga, pixels);
	}
}
