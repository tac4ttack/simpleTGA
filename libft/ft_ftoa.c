/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 17:09:09 by fmessina          #+#    #+#             */
/*   Updated: 2017/11/27 16:11:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <float.h>

char	*ft_ftoa(float n)
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
	res = ft_strjoin_frs1(ft_itoa(n), ".");
	n -= (int)n;
	(n < 0.0 ? n = -n : 0);
	n *= 10;
	i = 0;
	while (n * 10 != 0)
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
