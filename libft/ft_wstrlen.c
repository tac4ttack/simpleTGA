/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:24:23 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 16:24:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstrlen(wchar_t *str)
{
	int i;
	int final;

	i = -1;
	final = 0;
	while (str[++i])
		final += ft_wcharlen(str[i]);
	return (final);
}
