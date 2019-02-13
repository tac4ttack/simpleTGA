/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 15:00:15 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/13 11:01:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char			*ft_ltoa(long n)
{
	char	*s;
	size_t	len;

	if (n == LONG_MAX)
		return (ft_strdup("9223372036854775807"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = ft_intlen(n) + 1;
	if (!(s = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len - 1] = '\0';
	while (n)
	{
		len--;
		s[len - 1] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
