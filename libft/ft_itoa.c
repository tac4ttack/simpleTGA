/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 21:46:07 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:11:15 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_itoalen(int n)
{
	int i;

	i = 1;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*nb;
	int		i;
	char	neg;

	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648\0"));
		neg = 1;
		n = -n;
	}
	else
		neg = 0;
	i = ft_itoalen(n) + neg;
	if (!(nb = (char *)malloc(i + 1)))
		return (0);
	nb[i] = '\0';
	while (i != neg)
	{
		nb[--i] = (n % 10) + 48;
		n /= 10;
	}
	if (neg)
		nb[0] = '-';
	return (nb);
}
