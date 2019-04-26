/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawtc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/26 10:59:39 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool	tga_process_rawtc(t_tga *tga)
{
	if (tga)
	{
		if (tga->depth == 15)
			return (tga_truecolor_15bpp(tga, tga->pixels));
		else if (tga->depth == 16)
			return (tga_truecolor_16bpp(tga, tga->pixels));
		else if (tga->depth == 24)
			return (tga_truecolor_24bpp(tga, tga->pixels));
		else if (tga->depth == 32)
			return (tga_truecolor_32bpp(tga, tga->pixels));
		else
			return (tga_berror("Invalid pixel depth for RAW TC format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_rawtc()!", tga));
}
