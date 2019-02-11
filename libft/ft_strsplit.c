/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:54:31 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 17:24:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static const char	*ft_str_find_nxt(const char *str, char c, int n)
{
	if (n)
		while (*str != '\0' && *str == c)
			str++;
	else
		while (*str != '\0' && *str != c)
			str++;
	return (str);
}

static int			ft_str_splits(const char *str, char s)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str = ft_str_find_nxt(str, s, 1);
		if (*str != '\0')
		{
			i++;
			str = ft_str_find_nxt(str, s, 0);
		}
	}
	return (i);
}

static char			**ft_reset(char **ret, int len)
{
	int i;

	i = 0;
	while (i < len)
		free(ret[i]);
	free(ret);
	return (NULL);
}

char				**ft_strsplit(char const *str, char c)
{
	char		**ret;
	int			i;
	const char	*next;

	if (str == NULL)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (ft_str_splits(str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		str = ft_str_find_nxt(str, c, 1);
		if (*str)
		{
			next = ft_str_find_nxt(str, c, 0);
			ret[i] = ft_strsub(str, 0, next - str);
			if (ret[i] == NULL)
				return (ft_reset(ret, i));
			i++;
			str = next;
		}
	}
	ret[i] = 0;
	return (ret);
}
