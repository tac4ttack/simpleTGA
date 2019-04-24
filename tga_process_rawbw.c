/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rawbw.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 13:06:16 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool	tga_process_rawbw(t_tga *tga)
{
	if (tga)
	{
		if (tga->depth == 8)
			return (tga_blackwhite_8bpp(tga));
		// else if (tga->depth == 16)
			//tga_blackwhite_16bpp(tga, pixels);		// TODO!
		else
			return (tga_berror("Invalid pixel depth for RAW BW format!", tga));
	}
	return (tga_berror("NULL TGA pointer in tga_process_rawbw()!", tga));
}