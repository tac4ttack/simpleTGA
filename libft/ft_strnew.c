/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:46:04 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 17:23:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char *mem;

	mem = (char *)malloc(size + 1);
	if (!mem)
		return (NULL);
	ft_memset(mem, 0, size + 1);
	return (mem);
}
