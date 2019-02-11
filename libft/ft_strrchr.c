/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 04:32:15 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 17:24:17 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(char const *s, int c)
{
	const char *tmp;

	tmp = NULL;
	while (*s)
	{
		if (*s == c)
			tmp = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)tmp);
}
