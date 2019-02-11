/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_draw.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adalenco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:46:44 by adalenco          #+#    #+#             */
/*   Updated: 2018/02/26 19:46:44 by adalenco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				mlx_img_pix_put(t_frame *sce, int x, int y, int color)
{
	int			i;

	if (x < sce->w && y < sce->h && x >= 0 && y >= 0)
	{
		i = ((x * (sce->bpp / 8)) + (y * sce->row));
		if (sce->endian == 0)
		{
			sce->pix[i] = (color & 0x000000FF);
			sce->pix[i + 1] = (color & 0x0000FF00) >> 8;
			sce->pix[i + 2] = (color & 0x00FF0000) >> 16;
			sce->pix[i + 3] = (color & 0xFF000000) >> 24;
		}
		else
		{
			sce->pix[i] = (color & 0x000000FF) >> 24;
			sce->pix[i + 1] = (color & 0x0000FF00) >> 16;
			sce->pix[i + 2] = (color & 0x00FF0000) >> 8;
			sce->pix[i + 3] = (color & 0xFF000000);
		}
	}
	return (0);
}

void			mlx_img_line_hor(t_frame *sce, t_p2i p1, t_p2i p2, int c)
{
	int			i;
	int			accum;
	t_p2i		p;

	i = 1;
	p.x = p1.x;
	p.y = p1.y;
	mlx_img_pix_put(sce, p.x, p.y, c);
	accum = ft_abs(p2.x - p1.x) / 2;
	while (i <= ft_abs(p2.x - p1.x))
	{
		i++;
		p.x += ((p2.x - p1.x) > 0) ? 1 : -1;
		accum += ft_abs(p2.y - p1.y);
		if (accum >= ft_abs(p2.x - p1.x))
		{
			accum -= ft_abs(p2.x - p1.x);
			p.y += ((p2.y - p1.y) > 0) ? 1 : -1;
		}
		mlx_img_pix_put(sce, p.x, p.y, c);
	}
}

void			mlx_img_line_ver(t_frame *sce, t_p2i p1, t_p2i p2, int c)
{
	int			i;
	int			accum;
	t_p2i		p;

	i = 1;
	p.x = p1.x;
	p.y = p1.y;
	mlx_img_pix_put(sce, p.x, p.y, c);
	accum = ft_abs(p2.y - p1.y) / 2;
	while (i <= ft_abs(p2.y - p1.y))
	{
		i++;
		p.y += ((p2.y - p1.y) > 0) ? 1 : -1;
		accum += ft_abs(p2.x - p1.x);
		if (accum >= ft_abs(p2.y - p1.y))
		{
			accum -= ft_abs(p2.y - p1.y);
			p.x += ((p2.x - p1.x) > 0) ? 1 : -1;
		}
		mlx_img_pix_put(sce, p.x, p.y, c);
	}
}

void			mlx_img_line(t_frame *sce, t_p2i p1, t_p2i p2, int c)
{
	if (ft_abs(p2.x - p1.x) > ft_abs(p2.y - p1.y))
		mlx_img_line_hor(sce, p1, p2, c);
	else
		mlx_img_line_ver(sce, p1, p2, c);
}
