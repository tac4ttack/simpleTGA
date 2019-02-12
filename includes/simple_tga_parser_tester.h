#ifndef SIMPLE_TGA_PARSER_TESTER_H
# define SIMPLE_TGA_PARSER_TESTER_H

# include "mlx.h"
# include "libft.h"
# include "simple_tga_parser.h"

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
    t_key				*mlx_keys;
	void				*frame_buffer_pointer;
	int					*frame_buffer_data;
	t_tga_header		target_tga;
	void				*target_img_pointer;
	unsigned int		*target_img_data;
	int					target_img_size[2];
	int					target_img_offset[2];
	char				*target_file;
	int					bpp;
	int					size_line;
	int					endian;
}						t_env;

int						get_top_left_corner_x(t_env *env);
int						get_top_left_corner_y(t_env *env);
int						init(t_env *env);
void					mlx_key_events(t_env *env);
int						mlx_key_press(int key, t_env *env);
int						mlx_key_release(int key, t_env *env);
int						mlx_main_loop(t_env *env);
int						mlx_mouse_events(int btn, int x, int y, t_env *env);
int						quit(t_env *e);
int						set_mlx_hooks(t_env *env);
void					s_error(char *str, t_env *e);

#endif
