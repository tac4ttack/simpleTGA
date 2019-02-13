/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:41:05 by fmessina          #+#    #+#             */
/*   Updated: 2016/11/23 16:40:06 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <string.h>

void	ft_putendl(char const *s)
{
	if (s != NULL)
	{
		ft_putstr(s);
		write(1, "\n", 1);
	}
}
