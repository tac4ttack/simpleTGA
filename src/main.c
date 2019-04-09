/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:32:13 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/09 16:43:34 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"
#include "simple_tga_parser_tester.h"

int		main(int ac, char **av)
{
	t_env			*env = NULL;
	unsigned int	*tga_pixels = NULL;

	if (!(env = malloc(sizeof(t_env))))
		s_error("\x1b[2;31mCan't allocate memory for environment\x1b[0m", NULL);
	ft_bzero(env, sizeof(t_env));

	if (init(env) != 0)
		s_error("\x1b[2;31mCan't initialize environment\x1b[0m", env);

	if (ac == 2 && av[1])
	{
		env->target_file = ft_strdup(av[1]);

		if (!(tga_pixels = tga_load_file(env->target_file,\
										(size_t*)&env->target_img_size[0],\
										(size_t*)&env->target_img_size[1])))
			s_error("Could not load target TGA!", env);

		fprintf(stdout, "File loaded (w = %d | h = %d)\n", env->target_img_size[0], env->target_img_size[1]);

		if (!(env->target_img_pointer = mlx_new_image(
					env->mlx_pointer,
					env->target_img_size[0],
					env->target_img_size[1])))
			s_error("Could not load create buffer for target", env);

		env->target_img_data = (unsigned int *)mlx_get_data_addr(
												env->target_img_pointer,\
												&env->bpp,\
												&env->size_line,\
												&env->endian);

		memcpy(env->target_img_data, tga_pixels,\
				(env->target_img_size[0] * env->target_img_size[1] * 4));
	}
	else
		if (!(env->target_img_pointer = mlx_xpm_file_to_image(env->mlx_pointer, "./tga_files/doge/doge.xpm", &env->target_img_size[0], &env->target_img_size[1])))
			s_error("could not load xpm!", env);


	if (set_mlx_hooks(env) != 0)
		s_error("\x1b[2;31mCan't setup MLX hooks\x1b[0m", env);

	return (0);
}
