/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:09:09 by fmessina          #+#    #+#             */
/*   Updated: 2018/04/22 16:35:58 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <float.h>

static char		*ft_ftoa_check_sign(float n)
{
	char	*res;

	if (n < 0.0f && n > -1.f)
	{
		res = ft_strjoin_frs2("-", ft_itoa(n));
		res = ft_strjoin_frs1(res, ".");
	}
	else
		res = ft_strjoin_frs1(ft_itoa(n), ".");
	return (res);
}

char			*ft_ftoa(float n)
{
	char	*res;
	int		neg;
	int		tmp;
	int		i;

	neg = 0;
	if (n == FLT_MAX)
		return ("3.402823e+38");
	if (n == FLT_MIN)
		return ("1.175494e-38");
	res = ft_ftoa_check_sign(n);
	n -= (int)n;
	(n < 0.0 ? n = -n : 0);
	n *= 10;
	i = 0;
	while (n * 10 != 0 && i < 8)
	{
		tmp = (int)n;
		res = ft_strjoin_free(res, ft_itoa(n));
		n -= tmp;
		n *= 10;
		i++;
	}
	(i == 0 && n * 10 == 0 ? res = ft_strjoin_frs1(res, "0") : 0);
	return (res);
}
