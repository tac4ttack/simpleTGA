/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:59:21 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/13 11:19:53 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

static char	*dump_data(const char *target, size_t *length)
{
	int		fd;
	char	*data_raw;
	ssize_t	read_return;

	if (!(data_raw = malloc(sizeof(char) * (*length + 1))))
	{
		*length = 0;
		return (NULL);
	}
	if ((fd = open(target, O_RDONLY)) < 0)
	{
		*length = 0;
		if (data_raw)
			free(data_raw);
		return (NULL);
	}
	read_return = read(fd, data_raw, *length);
	data_raw[read_return] = '\0';
	close(fd);
	return (data_raw);
}

char		*ft_read_file(const char *target, size_t *target_size)
{
	if (target && target_size)
	{
		if ((*target_size = ft_file_len(target)) == 0)
			return (NULL);
		return (dump_data(target, target_size));
	}
	if (target_size)
		*target_size = 0;
	return (NULL);
}
