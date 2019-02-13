/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 16:35:40 by ntoniolo          #+#    #+#             */
/*   Updated: 2018/04/22 16:35:41 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memnew(void *ptr, size_t mem_size)
{
	char	*new;

	if (!(new = ft_memalloc(mem_size)))
		return (NULL);
	ft_memcpy(new, ptr, mem_size);
	return ((void*)new);
}
