/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:46:22 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/16 18:56:48 by fmessina         ###   ########.fr       */
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

		if (!(env->mlx_window = mlx_new_window(env->mlx_pointer, WIDTH + WIDTH_OFF, HEIGHT,	"Just another simple TGA file parser")))
			s_error("\x1b[2;31mCould not create application window\x1b[0m", NULL);


		// BACKGROUND AKA FRAME_BUFFER
		int bpp, row, endian;
		if (!(env->frame_buffer_data = malloc(sizeof(int) * (WIDTH + WIDTH_OFF) * HEIGHT)))
			s_error("\x1b[2;31mCould not allocate frame buffer\x1b[0m", NULL);
		if (!(env->frame_buffer_pointer = mlx_new_image(env->mlx_pointer, (WIDTH + WIDTH_OFF), HEIGHT)))
			s_error("\x1b[2;31mCould not create frame buffer\x1b[0m", NULL);
		if (!(env->frame_buffer_data = (int*)mlx_get_data_addr(env->frame_buffer_pointer, &bpp, &row, &endian)))
			s_error("\x1b[2;31mCould not get frame buffer data pointer\x1b[0m", NULL);
		for (size_t i = 0; i < (WIDTH + WIDTH_OFF) * HEIGHT; i++)
		{
			if (i - ((i / (WIDTH + WIDTH_OFF)) * (WIDTH + WIDTH_OFF)) > 800)
				env->frame_buffer_data[i] = 0;
			else
				env->frame_buffer_data[i] = BG_COLOR;
		}

		env->target_img_pointer = NULL;
		env->target_img_data = NULL;
		env->target_file = NULL;

		return (0);
	}
	return (1);
}
