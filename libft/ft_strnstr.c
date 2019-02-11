/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:55:15 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 17:24:04 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t i;
	size_t j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s2[j] && i + j < n && s1[i + j] && s1[i + j] == s2[j])
			j++;
		if (s2[j] == 0)
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
