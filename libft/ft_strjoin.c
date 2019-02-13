/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:07:00 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:44:15 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(r = malloc(sizeof(s1) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		r[i] = (char)s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		r[j + i] = (char)s2[i];
		i++;
	}
	r[i++ + j] = '\0';
	return (r);
}
