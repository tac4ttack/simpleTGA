/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:19 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/27 18:49:02 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

bool	tga_process_pixels(t_tga *tga)
{
	if (tga)
	{
		if (!(tga->pixels = (unsigned int *)malloc(tga->n_pix \
													* sizeof(unsigned int))))
			return (tga_berror("Failed to allocate for pixels data!", tga));
		bzero((void*)tga->pixels, tga->n_pix * sizeof(unsigned int));
		if (tga->header->img_type == 1 || tga->header->img_type == 2 \
				|| tga->header->img_type == 3)
			return (tga_process_raw(tga));
		else if (tga->header->img_type == 9 || tga->header->img_type == 10 \
				|| tga->header->img_type == 11)
			return (tga_process_rle(tga));
		else
			return (tga_berror("TGA file format type is invalid!", tga));
	}
	else
		return (tga_berror("NULL TGA pointer in tga_process_pixels()!", tga));
}
