/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 05:50:00 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:39:10 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char	*t1;
	char	*t2;

	t1 = (char *)src;
	t2 = (char *)dst;
	if (t1 < t2)
	{
		t1 += len - 1;
		t2 += len - 1;
		while (len > 0)
		{
			*t2-- = *t1--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*t2++ = *t1++;
			len--;
		}
	}
	return (dst);
}
