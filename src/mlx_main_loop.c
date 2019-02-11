/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main_loop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:44:28 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/11 16:13:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

int		mlx_main_loop(t_env *env)
{
	if (env)
	{
		mlx_key_events(env);
		mlx_clear_window(env->mlx_pointer, env->mlx_window);

		mlx_put_image_to_window(env->mlx_pointer, env->mlx_window, env->frame_buffer_pointer, 0, 0);
		mlx_put_image_to_window(env->mlx_pointer, env->mlx_window, env->target_img_pointer, get_top_left_corner_x(env), get_top_left_corner_y(env));

		mlx_string_put(env->mlx_pointer, env->mlx_window, 5, 5, 0xffffff, env->target_file);
	}
	return (0);
}
