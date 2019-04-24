/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:09:03 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 11:26:04 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"
#include "simple_tga_parser_tester.h"

static unsigned int	invert_pixel_alpha(const unsigned int target)
{
	return ((~target & 0xff000000) | (target & 0x00ffffff));
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
			img[i] = invert_pixel_alpha(img[i]);
			i++;
		}
	}
}
