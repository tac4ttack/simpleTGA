/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawbw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:55:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rawbw(t_tga *tga, unsigned int *pixels)
{
	if (tga && pixels)
	{
		if (tga->depth == 8)
			tga_blackwhite_8bpp(tga, pixels);
		// else if (tga->depth == 16)
			//tga_blackwhite_16bpp(tga, pixels);		// TODO!
		else
			tga_error("Invalid pixel depth for RAW BW format!", pixels);
	}
}
