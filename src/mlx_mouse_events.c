/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:50:17 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/12 10:16:38 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int		mlx_mouse_events(int btn, int x, int y, t_env *env)
{
	if (btn == 1 && env)
	{
		printf("mouse event!\nx = %d\ny = %d\n\n", x, y);
		return (0);
	}
	else
		return (1);
}
