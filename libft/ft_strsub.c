/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:34:30 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/27 19:31:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = -1;
	if (s == NULL)
		return (NULL);
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (++i < len)
		new[i] = s[start + i];
	new[i] = '\0';
	return (new);
}
