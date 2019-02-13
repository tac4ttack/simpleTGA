/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:12:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/12/06 16:03:05 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char const *str)
{
	long res;
	long neg;

	res = 0;
	neg = 0;
	if (str)
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
			|| *str == '\f' || *str == '\v')
			str++;
		if (*str == '-')
		{
			neg = 1;
			str++;
		}
		else if (*str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			res += *str++ - '0';
			(*str >= '0' && *str <= '9' ? res *= 10 : 0);
		}
	}
	return (neg ? -res : res);
}
