/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:44:28 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/09 11:09:07 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int		mlx_main_loop(t_env *env)
{
	if (env)
	{
		mlx_key_events(env);
		mlx_clear_window(env->mlx_pointer, env->mlx_window);

		mlx_put_image_to_window(env->mlx_pointer,\
								env->mlx_window,\
								env->frame_buffer_pointer,\
								0,\
								0);
		mlx_put_image_to_window(env->mlx_pointer,\
								env->mlx_window,\
								env->target_img_pointer,\
								get_top_left_corner_x(env),\
								get_top_left_corner_y(env));

		if (env->target_file)
			mlx_string_put(env->mlx_pointer, env->mlx_window, 5, 5,	0xff0000, \
							env->target_file);
		else
			mlx_string_put(env->mlx_pointer, env->mlx_window, 5, 5, 0xff0000, \
							"default");
	}
	return (0);
}
