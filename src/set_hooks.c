/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:56:08 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/12 10:16:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int		set_mlx_hooks(t_env *env) {
	if (env)
	{
		mlx_hook(env->mlx_window, DESTROYNOTIFY, KEYRELEASEMASK, quit, env);
		mlx_hook(env->mlx_window, KEYPRESS, KEYPRESSMASK, mlx_key_press, env);
		mlx_hook(env->mlx_window, KEYRELEASE, KEYRELEASEMASK, mlx_key_release, env);
		mlx_mouse_hook(env->mlx_window, mlx_mouse_events, env);
		mlx_loop_hook(env->mlx_pointer, mlx_main_loop, env);
		mlx_loop(env->mlx_pointer);
		return (0);
	}
	else
		return (1);
}
