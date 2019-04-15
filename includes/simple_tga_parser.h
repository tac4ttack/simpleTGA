/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_tga_parser.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:08:50 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/15 17:28:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_TGA_PARSER_H
# define SIMPLE_TGA_PARSER_H

# include <stdlib.h>    // required for NULL size_t exit bidule
# include <sys/stat.h>   // required for stat()
# include <fcntl.h>      // required for open()
# include <unistd.h>    // required for read()
# include <stdio.h>     // required for printf()
# include <string.h>    // required for bzero()

# ifdef DEBUG
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

// Pragma required to disable padding in next structure
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
	unsigned char		pixel_depth;
	unsigned char		image_descriptor;
	char				end_padding[3];	// inutile si pragma pack?
}						t_tga_header;
# pragma pack(pop)

typedef struct			s_tga_info
{
	void				*data;
	unsigned int		*pixels;
	t_tga_header		*header;
	size_t				file_size;
	size_t				pixels_nbytes;
	unsigned short		image_origin;
	size_t				depth;
	size_t				width;
	size_t				height;
	unsigned short		image_attributes;
	int					data_offset;
	int					extension_offset;
	int					developer_offset;
	char				*signature;
	char				*id;
}						t_tga_info;


/*
**	Will return NULL if failed, plus it will try to output on the stderr
*/
unsigned int			*tga_load_file(const char *target, \
										size_t *width, \
										size_t *height,
										size_t *bpp);

void					*tga_error(const char *message, void *trash);

void					*tga_process_file(const char *target, \
											size_t *target_size);

unsigned int			*tga_process_pixels(t_tga_info *tga);

void					tga_process_rawbw(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_process_rawcm(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_process_rawtc(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_process_raw_packet(t_tga_info *tga, \
												unsigned int *pix_data, \
												size_t cursors[3]);

void					tga_process_rle_packet(t_tga_info *tga, \
												unsigned int *pix_data, \
												size_t cursors[3]);

void					tga_process_rlebw(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_process_rlecm(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_process_rletc(t_tga_info *tga, \
											unsigned int *pix_data);

void	 				tga_blackwhite_8bpp(t_tga_info *tga, \
											unsigned int *pix_data);

// void					tga_colormapped_15bpp(t_tga_info *tga, \
// 												unsigned int *pix_data);

// void					tga_colormapped_16bpp(t_tga_info *tga, \
// 												unsigned int *pix_data);

void					tga_colormapped_24bpp(t_tga_info *tga, \
												unsigned int *pix_data);

void					tga_colormapped_32bpp(t_tga_info *tga, \
												unsigned int *pix_data);

void					tga_truecolor_15bpp(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_truecolor_16bpp(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_truecolor_24bpp(t_tga_info *tga, \
											unsigned int *pix_data);

void					tga_truecolor_32bpp(t_tga_info *tga, \
											unsigned int *pix_data);

void	 				tga_blackwhite_8bpp_single(t_tga_info *tga, \
													unsigned int *pix_data, \
													const int dst, \
													const int src);

void					tga_truecolor_15bpp_single(t_tga_info *tga, \
													unsigned int *pix_data, \
													const int dst, \
													const int src);

void					tga_truecolor_16bpp_single(t_tga_info *tga, \
													unsigned int *pix_data, \
													const int dst, \
													const int src);

void					tga_truecolor_24bpp_single(t_tga_info *tga, \
													unsigned int *pix_data, \
													const int dst, \
													const int src);

void					tga_truecolor_32bpp_single(t_tga_info *tga, \
													unsigned int *pix_data, \
													const int dst, \
													const int src);

#endif
