/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:21:49 by fmessina          #+#    #+#             */
/*   Updated: 2017/06/23 16:36:09 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int		ft_get_double_len(double n, unsigned int precision)
{
	unsigned int	len;
	double			x;

	len = 1;
	x = n;
	if (x < 1.0)
		len++;
	while (x >= 1)
	{
		len++;
		x /= 10.0;
	}
	return (len + precision + 1);
}

static void				ft_dot(char *buf, double n,
								unsigned int precision, const char *map)
{
	long	x;

	if (!precision)
		return ;
	*(buf++) = '.';
	n -= (double)((__int128)n);
	x = (long)(n * ft_pow(10, (int)precision));
	while (precision--)
	{
		buf[precision] = map[x % 10];
		x /= 10.0;
	}
}

char					*ft_dtoa(double n, unsigned int precision)
{
	char			*buf;
	const char		neg = (n < 0.0 || *((long *)&n) < 0) ? 1 : 0;
	unsigned int	len;
	const char		*map = "0123456789";

	if (neg)
		n = -n;
	len = ft_get_double_len(n, precision) + (unsigned int)neg -
		((!precision) ? 1 : 0);
	if (!(buf = malloc(sizeof(char) * len)))
		return (NULL);
	buf[--len] = '\0';
	if (precision)
		len -= precision + 1.0;
	ft_dot(buf + len, n, precision, map);
	if (n < 1.0)
		buf[--len] = '0';
	while (n >= 1.0)
	{
		buf[--len] = map[(unsigned int)n % 10];
		n /= 10.0;
	}
	if (neg)
		buf[0] = '-';
	return (buf);
}
