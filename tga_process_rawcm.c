/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawcm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 18:08:57 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

bool	tga_process_rawcm(t_tga *tga)
{
	if (tga)
	{
		if (tga->header->cm_bpp == 8)
			return (tga_colormapped_8bpp(tga));
		else if (tga->header->cm_bpp == 15)
			return (tga_colormapped_15bpp(tga));
		else if (tga->header->cm_bpp == 16)
			return (tga_colormapped_16bpp(tga));
		else if (tga->header->cm_bpp == 24)
			return (tga_colormapped_24bpp(tga));
		else if (tga->header->cm_bpp == 32)
			return (tga_colormapped_32bpp(tga));
		else
			return (tga_berror("Invalid pixel depth for RAW CM format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_rawcm()!", tga));
}
