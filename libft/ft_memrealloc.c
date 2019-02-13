/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntoniolo <ntoniolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 23:51:36 by ntoniolo          #+#    #+#             */
/*   Updated: 2018/03/01 21:04:55 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrealloc(void *ptr, size_t size_old, size_t size_new)
{
	void	*new_ptr;

	if (!(new_ptr = ft_memalloc(size_new)))
		return (NULL);
	if (ptr)
		new_ptr = ft_memcpy(new_ptr, ptr, size_old);
	if (ptr)
		free(ptr);
	return (new_ptr);
}
