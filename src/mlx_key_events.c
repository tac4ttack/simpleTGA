/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:47:00 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/09 15:24:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

void	mlx_key_events(t_env *env)
{
	if (env)
	{
		(KP_ESC ? quit(env) : 0);
		(KP_UA ? env->target_img_offset[1]-- : 0);
		(KP_DA ? env->target_img_offset[1]++ : 0);
		(KP_LA ? env->target_img_offset[0]-- : 0);
		(KP_RA ? env->target_img_offset[0]++ : 0);

	}
	else
		s_error("\x1b[2;31mFatal error in 'mlx_key_events'\x1b[0m", env);
}
