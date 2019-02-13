/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 06:08:17 by fmessina          #+#    #+#             */
/*   Updated: 2018/04/22 16:35:04 by ntoniolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_ahtoi(char const *str)
{
	int	i;
	int len;
	int val;

	i = 0;
	len = ft_strlen(str);
	val = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (i < len && str[i] != 0)
	{
		if ((str[i] >= 48 && str[i] <= 57) || \
		(str[i] >= 65 && str[i] <= 70) || \
		(str[i] >= 97 && str[i] <= 102))
		{
			if (str[i] <= 57)
				val += (str[i] - 48) * (1 << (4 * (len - 1 - i)));
			else if (str[i] <= 65 && str[i] >= 70)
				val += (str[i] - 55) * (1 << (4 * (len - 1 - i)));
			else if (str[i] <= 97 && str[i] >= 102)
				val += (str[i] - 87) * (1 << (4 * (len - 1 - i)));
		}
		i++;
	}
	return (val);
}
