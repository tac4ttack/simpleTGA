/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 16:43:43 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/17 14:56:56 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_gnl_free(t_list **lst, int fd, char **str)
{
	t_gnl	*tmp_gnl;
	t_list	**tmp_lst;
	t_list	*next_lst;

	tmp_lst = lst;
	while (*tmp_lst)
	{
		tmp_gnl = (t_gnl *)((*tmp_lst)->content);
		if (tmp_gnl->fd == fd)
			break ;
		*tmp_lst = ((*tmp_lst)->next);
	}
	if (*tmp_lst)
	{
		next_lst = (*tmp_lst)->next;
		ft_strdel(&(tmp_gnl->buffer));
		ft_memdel((void **)&tmp_gnl);
		ft_memdel((void **)tmp_lst);
		*tmp_lst = next_lst;
	}
	ft_strdel(str);
}

static t_gnl	*ft_gnl_init(t_list **lst, int fd)
{
	t_gnl	*gnl;
	t_list	*tmp;
	int		b_size;

	b_size = ((BUFF_SIZE == 0) ? 1 : BUFF_SIZE);
	tmp = *lst;
	while (tmp)
	{
		gnl = (t_gnl *)(tmp->content);
		if (gnl->fd == fd)
			return (gnl);
		tmp = tmp->next;
	}
	gnl = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	gnl->buffer = ft_strnew(b_size);
	gnl->b_read = b_size;
	gnl->i = b_size;
	gnl->fd = fd;
	gnl->new_line = 1;
	tmp = ft_lstnew(gnl, sizeof(t_gnl));
	ft_memdel((void **)&gnl);
	ft_lstadd(lst, tmp);
	return ((t_gnl *)(tmp->content));
}

static int		ft_gnl_read(t_gnl *gnl, t_list **lst, char **tmp, char **line)
{
	int b_size;

	b_size = ((BUFF_SIZE == 0) ? 1 : BUFF_SIZE);
	if (gnl->i == gnl->b_read)
	{
		gnl->b_read = read(gnl->fd, gnl->buffer, b_size);
		if (gnl->b_read == -1)
		{
			ft_gnl_free(lst, gnl->fd, tmp);
			return (-1);
		}
		gnl->i = 0;
		if (gnl->b_read == 0)
		{
			if (gnl->new_line == 0)
			{
				*line = *tmp;
				return (1);
			}
		}
	}
	return (0);
}

static char		*ft_gnl_concat(t_gnl *gnl)
{
	int i;

	i = 0;
	gnl->new_line = 0;
	while (gnl->i + i < gnl->b_read)
	{
		if (gnl->buffer[gnl->i + i] == '\n')
		{
			gnl->new_line = 1;
			i++;
			break ;
		}
		i++;
	}
	gnl->i += i;
	return (ft_strsub(gnl->buffer, gnl->i - i, i - gnl->new_line));
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;
	char			*tmp;
	int				status;

	if (fd < 0 || !line || fd >= FD_MAX)
		return (-1);
	gnl = ft_gnl_init(&lst, fd);
	tmp = ft_strnew(0);
	while (gnl->b_read > 0)
	{
		if ((status = ft_gnl_read(gnl, &lst, &tmp, line)) != 0)
			return (status);
		while (gnl->i < gnl->b_read)
		{
			tmp = ft_strjoin_free(tmp, ft_gnl_concat(gnl));
			if (gnl->new_line == 1)
			{
				*line = tmp;
				return (1);
			}
		}
	}
	ft_gnl_free(&lst, fd, &tmp);
	return (0);
}
