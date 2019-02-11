/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:28:34 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 11:41:54 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (size > 0)
	{
		while (i < size && dst[i])
			i++;
		while (src[j] && size - 1 > i + j)
		{
			dst[i + j] = src[j];
			j++;
		}
		if (i < size)
			dst[i + j] = 0;
	}
	return (ft_strlen(src) + i);
}
