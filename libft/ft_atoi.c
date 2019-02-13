/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 06:08:17 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 14:58:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char const *str)
{
	int		i;
	int		val;
	int		neg;

	i = 0;
	val = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = 1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i] != 0)
	{
		val = (val * 10) + str[i] - 48;
		i++;
	}
	if (neg == 1)
		return (-val);
	else
		return (val);
}
