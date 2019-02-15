/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:46:22 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/13 16:37:06 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int		init(t_env *env) {
	if (env)
	{
		if (!(env->mlx_keys = (t_key *)malloc(sizeof(t_key))))
			s_error("\x1b[2;31mCan't initialize MLX keyboard management\x1b[0m", NULL);
		ft_bzero(env->mlx_keys, sizeof(t_key));

		if (!(env->mlx_pointer = mlx_init()))
			s_error("\x1b[2;31mCan't initialize MLX context\x1b[0m", NULL);

		if (!(env->mlx_window = mlx_new_window(env->mlx_pointer, WIDTH, HEIGHT,	"Just another simple TGA file parser")))
			s_error("\x1b[2;31mCould not create application window\x1b[0m", NULL);

		if (!(env->frame_buffer_pointer = mlx_new_image(env->mlx_pointer, WIDTH, HEIGHT)))
			s_error("\x1b[2;31mCould not create frame buffer\x1b[0m", NULL);

		int bpp, row, endian;
		if (!(env->frame_buffer_data = (int*)mlx_get_data_addr(env->frame_buffer_pointer, &bpp, &row, &endian)))
			s_error("\x1b[2;31mCould not get frame buffer data pointer\x1b[0m", NULL);

		env->target_img_pointer = NULL;
		env->target_img_data = NULL;
		env->target_file = NULL;

		return (0);
	}
	else
	return (1);
}
