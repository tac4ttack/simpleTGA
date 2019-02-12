/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:17:50 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/12 17:25:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

static int		tga_fetch_file_size(const char *target)
{
	struct stat	file_stat;

	if (stat(target, &file_stat) != 0)
		return (-1);
	else
		return ((size_t)file_stat.st_size);
}

static char		*tga_read_file(const char *target, size_t *length)
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

char			*tga_process_file(const char *target, size_t *target_size)
{
	if (target && target_size)
	{
		if ((*target_size = tga_fetch_file_size(target)) == -1)
			return (NULL);
		return (tga_read_file(target, target_size));
	}
	if (target_size)
		*target_size = 0;
	return (NULL);
}
