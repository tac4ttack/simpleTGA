/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mouse_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:50:17 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/09 11:56:39 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int		mlx_mouse_events(int btn, int x, int y, t_env *env)
{
	if (btn == 1 && env)
	{
		(void)x;
		(void)y;
		// printf("mouse event!\nx = %d\ny = %d\n\n", x, y);
		return (0);
	}
	else
		return (1);
}
