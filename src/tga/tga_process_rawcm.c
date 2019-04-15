/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawcm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/15 17:34:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rawcm(t_tga_info *tga, unsigned int *pix_data)
{
	if (tga && pix_data)
	{
		if (tga->header->cm_bpp == 8)
			;
		else if (tga->header->cm_bpp == 15)
			;
		else if (tga->header->cm_bpp == 16)
			;
		else if (tga->header->cm_bpp == 24)
			tga_colormapped_24bpp(tga, pix_data);
		else if (tga->header->cm_bpp == 32)
			tga_colormapped_32bpp(tga, pix_data);
	}
}
