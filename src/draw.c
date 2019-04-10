/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 15:06:30 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/10 15:14:25 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int     get_top_left_corner_x(t_env *env) {
    if (env)
        return ((WIDTH / 2) - (env->target_img_size[0] / 2) + env->target_img_offset[0]);
    else
        return (0);
}

int     get_top_left_corner_y(t_env *env) {
    if (env)
        return ((HEIGHT / 2) - (env->target_img_size[1] / 2) + env->target_img_offset[1]);
    else
        return (0);
}
