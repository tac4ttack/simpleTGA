/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_tga.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:32:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:32:47 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_TGA_H
# define SIMPLE_TGA_H

# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# ifdef DEBUG_SIMPLE_TGA
#  define DEBUG_TGA 1
# else
#  define DEBUG_TGA	0
# endif

# define TGA_TYPE_NODATA 0
# define TGA_TYPE_RAW_CM 1
# define TGA_TYPE_RAW_TC 2
# define TGA_TYPE_RAW_BW 3
# define TGA_TYPE_RLE_CM 9
# define TGA_TYPE_RLE_TC 10
# define TGA_TYPE_RLE_BW 11

# define TGA_IMG_ORI_BL 0
# define TGA_IMG_ORI_BR 1
# define TGA_IMG_ORI_TL 2
# define TGA_IMG_ORI_TR 3

# pragma pack(push, 1)

typedef struct			s_tga_header
{
	char				id_len;
	char				cm_type;
	char				img_type;
	unsigned short		cm_first_entry;
	unsigned short		cm_length;
	unsigned char		cm_bpp;
	unsigned short		x_origin;
	unsigned short		y_origin;
	unsigned short		image_width;
	unsigned short		image_heigth;
	unsigned char		bpp;
	unsigned char		image_descriptor;
}						t_tga_header;
# pragma pack(pop)

typedef struct			s_tga
{
	t_tga_header		*header;
	void				*data;
	unsigned int		*pixels;
	size_t				file_size;
	unsigned short		image_origin;
	size_t				depth;
	size_t				width;
	size_t				height;
	size_t				n_pix;
	int					data_offset;
	int					extension_offset;
	int					developer_offset;
	char				*signature;
	char				*id;
}						t_tga;

unsigned int			*tga_get_pixel_ptr(const t_tga *target);

t_tga					*tga_load_file(const char *target);

bool					tga_clean(t_tga *tga);

void					*tga_error(const char *message, t_tga *trash);

bool					tga_berror(const char *message, t_tga *trash);

bool					tga_post_process(t_tga *tga);

void					*tga_process_file(const char *target,
											size_t *target_size);

bool					tga_process_pixels(t_tga *tga);

bool					tga_process_raw(t_tga *tga);

bool					tga_process_rle(t_tga *tga);

bool					tga_process_raw_packet(t_tga *tga, size_t cursors[3]);

bool					tga_process_rle_packet(t_tga *tga, size_t cursors[3]);

bool					tga_blackwhite_8bpp(t_tga *tga, unsigned int *dst);

bool					tga_blackwhite_16bpp(t_tga *tga, unsigned int *dst);

bool					tga_colormapped_8bpp(t_tga *tga, unsigned int *dst);

bool					tga_colormapped_15bpp(t_tga *tga, unsigned int *dst);

bool					tga_colormapped_16bpp(t_tga *tga, unsigned int *dst);

bool					tga_colormapped_24bpp(t_tga *tga, unsigned int *dst);

bool					tga_colormapped_32bpp(t_tga *tga, unsigned int *dst);

bool					tga_truecolor_15bpp(t_tga *tga, unsigned int *dst);

bool					tga_truecolor_16bpp(t_tga *tga, unsigned int *dst);

bool					tga_truecolor_24bpp(t_tga *tga, unsigned int *dst);

bool					tga_truecolor_32bpp(t_tga *tga, unsigned int *dst);

bool					tga_blackwhite_8bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_blackwhite_16bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_colormapped_15bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_colormapped_16bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_colormapped_24bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_colormapped_32bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_truecolor_15bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_truecolor_16bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_truecolor_24bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

bool					tga_truecolor_32bpp_single(t_tga *tga, \
													const int dst, \
													const int src);

#endif
