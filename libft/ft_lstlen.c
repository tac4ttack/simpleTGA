/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 15:53:28 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 15:53:37 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	t_list *tmp;
	size_t len;

	len = 0;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
	}
	return (len);
}
