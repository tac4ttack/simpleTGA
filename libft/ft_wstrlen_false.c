/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen_false.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:25:19 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 16:25:31 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen_false(wchar_t *str)
{
	int i;
	int total;

	total = 0;
	i = -1;
	while (str[++i])
		total++;
	return (total);
}
