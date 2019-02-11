/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:31:06 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/11 15:06:22 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	flush(t_env *e)
{
	if (e->frame_buffer_pointer)
		mlx_destroy_image(e->mlx_pointer, e->frame_buffer_pointer);
	if (e->mlx_window)
		mlx_destroy_window(e->mlx_pointer, e->mlx_window);
	if (e)
		free(e);
}

void	s_error(char *str, t_env *e)
{
	ft_putendl("\n\x1b[2;31mOh no I just crashed!\x1b[0m");
	ft_putendl(str);
	flush(e);
	exit(EXIT_FAILURE);
}

// void	p_error(char *str, t_env *e)
// {
// 	ft_putendl("\n\x1b[2;31mOh no I just crashed!\x1b[0m");
// 	ft_putendl(str);
// 	perror(NULL);
// 	flush(e);
// 	exit(EXIT_FAILURE);
// }

int		quit(t_env *e)
{
	flush(e);
	ft_putendl("Exiting");
	exit(EXIT_SUCCESS);
	return (0);
}
