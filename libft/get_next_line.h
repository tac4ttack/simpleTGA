/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:45:05 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/13 11:04:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

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
