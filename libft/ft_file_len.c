/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 11:11:42 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/13 11:19:20 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/stat.h>

size_t	ft_file_len(const char *target)
{
	struct stat	file_stat;

	if (stat(target, &file_stat) != 0)
		return (0);
	else
		return ((size_t)file_stat.st_size);
}
