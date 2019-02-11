/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:45:05 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 14:58:41 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 0
# define FD_MAX 5000

typedef struct	s_gnl
{
	char		*buffer;
	int			b_read;
	int			i;
	int			new_line;
	int			fd;
}				t_gnl;

int				get_next_line(const int fd, char **line);
#endif
