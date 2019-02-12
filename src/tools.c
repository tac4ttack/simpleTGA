/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:31:06 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/12 20:20:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"
#include "simple_tga_parser_tester.h"

void	flush(t_env *env)
{
	fprintf(stdout,
			"\n&mlx_pointer = %p\n"
			"&mlx_window = %p\n"
			"&mlx_keys = %p\n"
			"&frame_buffer_pointer = %p\n"
			"&frame_buffer_data = %p\n"
			"&target_img_pointer = %p\n"
			"&target_img_data = %p\n"
			"&target_file = %p\n",
			env->mlx_pointer,
			env->mlx_window,
			env->mlx_keys,
			env->frame_buffer_pointer,
			env->frame_buffer_data,
			env->target_img_pointer,
			env->target_img_data,
			env->target_file
			);

	if (env->frame_buffer_pointer)
	{
		fprintf(stdout, "\nfreeing frame_buffer_pointer (mlx_destroy_image)\n", NULL);
		mlx_destroy_image(env->mlx_pointer, env->frame_buffer_pointer);
	}
	if (env->mlx_keys)
	{
		fprintf(stdout, "freeing mlx_keys\n", NULL);
		free(env->mlx_keys);
		env->mlx_keys = NULL;
	}
	if (env->target_img_pointer)
	{
		fprintf(stdout, "freeing target_img_pointer (mlx_destroy_image)\n", NULL);
		mlx_destroy_image(env->mlx_pointer, env->target_img_pointer);

	}
	if (env->mlx_window)
	{
		fprintf(stdout, "freeing mlx_window (mlx_destroy_window)\n", NULL);
		mlx_destroy_window(env->mlx_pointer, env->mlx_window);
		if (env->mlx_pointer)
		{
			fprintf(stdout, "freeing mlx_pointer\n", NULL);
			free(env->mlx_pointer);
			env->mlx_pointer = NULL;
		}
	}

	if (env->target_file)
	{
		fprintf(stdout, "freeing target_file\n", NULL);
		free(env->target_file);
		env->target_file = NULL;
	}
	if (env)
	{
		fprintf(stdout, "freeing env\n", NULL);
		free(env);
		env = NULL;
	}


}

void	s_error(char *str, t_env *e)
{
	ft_putendl("\n\x1b[2;31mOh no I just crashed!\x1b[0m");
	ft_putendl(str);
	flush(e);
	while (1)
	;
	exit(EXIT_FAILURE);
}

int		quit(t_env *e)
{
	flush(e);
	ft_putendl("Exiting");
	while (1)
		;
	exit(EXIT_SUCCESS);
	return (0);
}
