/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_tga_parser.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:08:50 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/11 16:18:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_TGA_PARSER_H
# define SIMPLE_TGA_PARSER_H

// # include <stdlib.h>
// # include <unistd.h>

# include "mlx.h"
# include "libft.h"

# ifdef MAC_KEYS
#  include "mac_keys.h"
# elif LINUX_KEYS
#  include "linux_keys.h"
# endif

# define WIDTH  				800
# define HEIGHT 				600
# define DESTROYNOTIFY			17
# define KEYPRESSMASK			(1L<<0)
# define KEYRELEASEMASK			(1L<<1)
# define KEYPRESS				2
# define KEYRELEASE				3

typedef	struct			s_env
{
	void				*mlx_pointer;
	void				*mlx_window;
    t_key               *mlx_keys;
	void				*frame_buffer_pointer;
	int					*frame_buffer_data;
	void				*target_img_pointer;
	int					*target_img_data;
	int					target_img_size[2];
	int					target_img_offset[2];
	char				*target_file;

}						t_env;


int     get_top_left_corner_x(t_env *env);
int     get_top_left_corner_y(t_env *env);
int		init(t_env *env);
void	mlx_key_events(t_env *env);
int		mlx_key_press(int key, t_env *env);
int		mlx_key_release(int key, t_env *env);
int		mlx_main_loop(t_env *env);
int		mlx_mouse_events(int btn, int x, int y, t_env *env);
int		quit(t_env *e);
int		set_mlx_hooks(t_env *env);
void	s_error(char *str, t_env *e);

#endif
