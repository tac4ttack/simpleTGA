/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:48:04 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 16:51:44 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ft_taylor_sin(double angle)
{
	int			step;
	double		fact;
	double		square_angle;
	double		ret;

	square_angle = angle * angle;
	ret = angle;
	step = 0;
	fact = 1;
	while (step++ < 10)
	{
		angle = -angle * square_angle;
		fact = (fact + fact) * step * (step + step + 1);
		ret = ret + angle / fact;
	}
	return (ret);
}

double			ft_sin(double angle)
{
	int			sign;
	double		pi;

	pi = 3.141592653589793;
	sign = 1;
	if (angle < 0)
	{
		angle = -angle;
		sign = -1;
	}
	if (angle == 0)
		return (0);
	else if (angle == pi / 2)
		return (1);
	else if (angle > pi / 2)
		angle = pi - angle;
	return (sign * ft_taylor_sin(angle));
}
