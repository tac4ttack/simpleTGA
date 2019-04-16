/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawtc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 15:06:02 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rawtc(t_tga *tga, unsigned int *pixels)
{
	if (tga && pixels)
	{
		if (tga->depth == 15)
			tga_truecolor_15bpp(tga, pixels);
		else if (tga->depth == 16)
			tga_truecolor_16bpp(tga, pixels);
		else if (tga->depth == 24)
			tga_truecolor_24bpp(tga, pixels);
		else if (tga->depth == 32)
			tga_truecolor_32bpp(tga, pixels);
	}
}
