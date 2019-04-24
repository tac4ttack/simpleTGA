/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:44:28 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 11:03:56 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

static void print_tga(t_env *env)
{
	char **split = ft_strsplit(tga_info, '\n');
	char **tmp = split;
	int i = 0;
	while (*split)
	{
		mlx_string_put(env->mlx_pointer, env->mlx_window, WIDTH + 10, 50 + 20 * i++, TXT_COLOR, *split);
		ft_memdel((void**)split++);
	}
	char mouse_info[100];
	sprintf(mouse_info, "mouse x = %d | y = %d \n", env->mouse_pos[0], env->mouse_pos[1]);
	mlx_string_put(env->mlx_pointer, env->mlx_window, WIDTH + 10, HEIGHT - 200, TXT_COLOR, mouse_info);
	ft_memdel((void**)(&tmp));
}

int		mlx_main_loop(t_env *env)
{
	if (env)
	{
		mlx_key_events(env);
		mlx_clear_window(env->mlx_pointer, env->mlx_window);

		mlx_put_image_to_window(env->mlx_pointer, env->mlx_window,\
								env->frame_buffer_pointer,\
								0, 0);

		mlx_put_image_to_window(env->mlx_pointer, env->mlx_window,\
								env->target_img_pointer,\
								get_top_left_corner_x(env),\
								get_top_left_corner_y(env));


		if (env->target_file)
		{
			mlx_string_put(env->mlx_pointer, env->mlx_window, 5, 5,	TXT_COLOR, \
							env->target_file);
			print_tga(env);
		}
		else
			mlx_string_put(env->mlx_pointer, env->mlx_window, 5, 5, TXT_COLOR, \
							"default");
	}
	return (0);
}
