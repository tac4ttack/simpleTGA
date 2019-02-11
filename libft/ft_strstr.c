/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:56:01 by fmessina          #+#    #+#             */
/*   Updated: 2017/11/12 18:02:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	char *tmp1;
	char *tmp2;

	if (!*s2)
		return ((char*)s1);
	while (*s1)
	{
		tmp1 = (char *)s1;
		tmp2 = (char *)s2;
		while (*tmp2 && *tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (!*tmp2)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
