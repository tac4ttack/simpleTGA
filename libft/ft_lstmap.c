/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:04:00 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:37:21 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*cur;
	t_list	*fst;
	t_list	*new;

	fst = NULL;
	if (lst != NULL)
	{
		while (lst)
		{
			new = (*f)(lst);
			if (fst)
			{
				cur->next = new;
				cur = cur->next;
			}
			else
			{
				fst = new;
				cur = fst;
			}
			lst = lst->next;
		}
	}
	return (fst);
}
