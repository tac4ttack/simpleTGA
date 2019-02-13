/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 11:07:10 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/13 11:00:47 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

float		ft_atof(char const *str)
{
	float	res;
	int		sign;
	int		i;

	res = 0;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		i = 1;
		while (ft_isdigit(*str))
		{
			res += (float)(*str - '0') / pow(10, i++);
			str++;
		}
	}
	return (res * sign);
}
