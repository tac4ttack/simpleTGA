/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 06:21:20 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:38:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	i = 0;
	tmp1 = dst;
	tmp2 = (void *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (tmp1);
}
