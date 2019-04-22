/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:09:03 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/18 10:04:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

unsigned int	invert_pixel_alpha(const unsigned int target)
{
	int 		result;

	POP("invert_pixel_alpha()");

	return (result = (((target & 0x000000ff)) + \
			((target & 0x0000ff00)) + \
			((target & 0x00ff0000)) + \
			((255 - target & 0xff000000))));
}

void			invert_image_alpha(unsigned int *img, size_t width, size_t height)
{
	size_t 		i;

	POP("invert_image_alpha()");

	i = 0;
	if (img)
	{
		while (i < width * height)
		{
			img[i] =  (((img[i] & 0x000000ff)) + \
						((img[i] & 0x0000ff00)) + \
						((img[i] & 0x00ff0000)) + \
						((255 - img[i] & 0xff000000)));
		i++;
		}
	}
}
