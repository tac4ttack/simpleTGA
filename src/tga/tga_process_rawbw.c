/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawbw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/11 12:50:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rawbw(t_tga_info *tga, unsigned int *pix_data)
{
	if (tga && pix_data)
	{
		if (tga->depth == 8)
			tga_blackwhite_8bpp(tga, pix_data);
		else
			tga_error("Invalid pixel depth for RAW BW format!", pix_data);
	}
}
