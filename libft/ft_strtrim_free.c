/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:53:34 by fmessina          #+#    #+#             */
/*   Updated: 2017/11/12 21:56:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim_free(char *s)
{
	char	*dest;
	size_t	l;
	size_t	j;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s);
	while ((j != l) && (s[j] == ' ' || s[j] == '\n' || s[j] == '\t'))
		j++;
	while ((l != j) && (s[l - 1] == ' ' || s[l - 1] == '\n'
			|| s[l - 1] == '\t'))
		l--;
	dest = ft_strnew(l - j);
	if (l > j)
	{
		while (j != l)
			dest[i++] = s[j++];
	}
	free(s);
	return (dest);
}
