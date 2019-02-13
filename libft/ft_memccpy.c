/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:58:25 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:37:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	char *t1;
	char *t2;

	t1 = (char*)src;
	t2 = (char*)dst;
	while (n > 0 && *t1 != c)
	{
		n--;
		*t2++ = *t1++;
	}
	if (n > 0 && *t1 == c)
	{
		*t2++ = *t1++;
		return ((void*)t2);
	}
	else
		return (NULL);
}
