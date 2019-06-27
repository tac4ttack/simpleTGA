/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_post_process.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 16:06:49 by fmessina          #+#    #+#             */
/*   Updated: 2019/06/27 18:48:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

static bool			flip_both(t_tga *tga)
{
	unsigned int	*new;
	size_t			i;
	size_t			size;

	i = 0;
	size = tga->n_pix - 1;
	if (tga)
	{
		if (!(new = (unsigned int *)malloc(sizeof(unsigned int) * tga->n_pix)))
			return (tga_berror("Failed creating temp flip buffer!", NULL));
		while (i < tga->n_pix)
		{
			new[i] = tga->pixels[size - i];
			i++;
		}
		free(tga->pixels);
		tga->pixels = new;
		return (true);
	}
	return (false);
}

static bool			flip_horizontally(t_tga *tga)
{
	unsigned int	*new;
	size_t			cur[2];

	cur[0] = tga->width - 1;
	cur[1] = 0;
	if (tga)
	{
		if (!(new = (unsigned int *)malloc(sizeof(unsigned int) * tga->n_pix)))
			return (tga_berror("Failed creating temp flip buffer!", NULL));
		while ((cur[1] * tga->width) + (tga->width - cur[0]) - 1 < tga->n_pix)
		{
			new[(cur[1] * tga->width) + (tga->width - cur[0]) - 1] = \
									tga->pixels[cur[0] + (cur[1] * tga->width)];
			if (cur[0]-- == 0)
			{
				cur[0] = tga->width - 1;
				cur[1]++;
			}
		}
		free(tga->pixels);
		tga->pixels = new;
		return (true);
	}
	return (false);
}

static bool			flip_vertically(t_tga *tga)
{
	unsigned int	*new;
	size_t			cur[2];

	cur[0] = 0;
	cur[1] = tga->height - 1;
	if (tga)
	{
		if (!(new = (unsigned int *)malloc(sizeof(unsigned int) * tga->n_pix)))
			return (tga_berror("Failed creating temp flip buffer!", NULL));
		while (((tga->height - cur[1] - 1) * tga->width) + cur[0] < tga->n_pix)
		{
			new[((tga->height - cur[1] - 1) * tga->width) + cur[0]] = \
								tga->pixels[(tga->height * cur[1]) + cur[0]];
			if (cur[0]++ == tga->width - 1)
			{
				cur[0] = 0;
				cur[1]--;
			}
		}
		free(tga->pixels);
		tga->pixels = new;
		return (true);
	}
	return (false);
}

bool				tga_post_process(t_tga *tga)
{
	if (tga)
	{
		if (tga->image_origin == 1)
			if (!flip_both(tga))
				return (tga_berror("Hozirontal & Vertical flip failed!", tga));
		if (tga->image_origin == 3)
			if (!flip_horizontally(tga))
				return (tga_berror("Hozirontal flip failed!", tga));
		if (tga->image_origin == 0)
			if (!flip_vertically(tga))
				return (tga_berror("Vertical flip failed!", tga));
		return (true);
	}
	return (tga_berror("NULL target pointer in tga_post_process()!", tga));
}
