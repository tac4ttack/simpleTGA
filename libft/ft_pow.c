/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 14:48:50 by fmessina          #+#    #+#             */
/*   Updated: 2017/06/21 15:21:10 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int n, int e)
{
	int		res;

	if (n < 0)
		n *= -1;
	if (e == 0)
		return (1);
	if ((e < 0) || (n == 0))
		return (0);
	res = 1;
	while (e--)
		res *= n;
	return (res);
}

double	ft_dpow(double n, double e)
{
	double	ret;
	int		neg;

	neg = e > 0 ? 0 : 1;
	ret = 1;
	if (n == 1 || e == 0)
		return (1);
	else if (n == 0)
		return (0);
	e = neg ? -e : e;
	while (e--)
		ret *= n;
	if (neg)
		ret = 1 / ret;
	return (ret);
}
