/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:32:13 by adalenco          #+#    #+#             */
/*   Updated: 2019/02/11 16:20:13 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

int		main(int ac, char **av)
{
	t_env	*env;

	if (ac == 2 && av[1])
	{
		if (!(env = malloc(sizeof(t_env))))
			s_error("\x1b[2;31mCan't allocate memory for environment\x1b[0m", NULL);
		ft_bzero(env, sizeof(t_env));

		if (init(env) != 0)
			s_error("\x1b[2;31mCan't initialize environment\x1b[0m", env);

		env->target_file = ft_strdup(av[1]);


		// Loading default image
		if (!(env->target_img_pointer = mlx_xpm_file_to_image(env->mlx_pointer, "./doge/doge.xpm", &env->target_img_size[0], &env->target_img_size[1])))
			s_error("could not load xpm!", env);
		// Loading target image
		// load_target_tga(env, av[1]);

		if (set_mlx_hooks(env) != 0)
			s_error("\x1b[2;31mCan't setup MLX hooks\x1b[0m", env);
	}
	else
	{
		ft_putendl("usage: ./simple_tga_parser [TGA file to open]");
	}

	// ft_bzero(e, sizeof(t_env));
	// init(e, ac, av[1]);
	// set_hooks(e);
	return (0);
}
