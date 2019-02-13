/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 13:38:10 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 13:39:31 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_error(char *error_str)
{
	ft_putstr_fd("ERROR", STDERR_FILENO);
	if (error_str != NULL)
	{
		ft_putstr_fd(" : ", STDERR_FILENO);
		ft_putendl_fd(error_str, STDERR_FILENO);
	}
	exit(1);
}
