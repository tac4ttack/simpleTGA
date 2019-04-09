/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:19 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/09 17:22:00 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

# define TGA_LR(x)				((x & 0x000000ff) << 24)
# define TGA_LG(x)				((x & 0x0000ff00) << 8)
# define TGA_LB(x)				((x & 0x00ff0000) >> 8)
# define TGA_LA(x)				((x & 0xff000000) >> 24)
# define TGA_L(x)				(TGA_LR(x) | TGA_LG(x) | TGA_LB(x) | TGA_LA(x))

static void tga_process_32bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t i;
	unsigned int *iterator;

	i = 0;
	iterator = (unsigned int *)(tga->data + sizeof(t_tga_header));
	while (i < tga->width * tga->height)
	{
		pixels[i] = iterator[i];
		if (i == 0 || i == 3 || i == tga->width -1 )
		fprintf(stdout, "debug | iterator = %#010x | pixel = %#010x\n", iterator[i], pixels[i]);
		i++;
	}
}

void tga_process_24bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t i;
	unsigned char *iterator;

	i = 0;
	iterator = (unsigned char *)(tga->data + sizeof(t_tga_header));
	while (i < tga->width * tga->height * 3)
	{
		*pixels = ((iterator[i]) + \
					(iterator[i + 1] << 8) + \
					(iterator[i + 2] << 16) + \
					(0xff << 24));
		if (i == 0)
			fprintf(stdout, "debug i = %zu | iterator = %02hhx %02hhx %02hhx  | pixel = %#010x\n", i, iterator[i], iterator[i + 1], iterator[i + 2], *pixels);
		i += 3;
		pixels++;
	}
}

void tga_process_16bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t i;
	unsigned char *iterator;
	unsigned char comp[4];

	i = 0;
	iterator = (unsigned char *)(tga->data + sizeof(t_tga_header));
	while (i < tga->width * tga->height * 2)
	{
        comp[0] = 255 * ((iterator[i + 1] & 0x80) >> 7);
        comp[1] = (iterator[i + 1] >> 2) & 0x1F;
        comp[2] = ((iterator[i + 1] << 3) & 0x1C) | ((iterator[i] >> 5) & 0x07);
        comp[3] = (iterator[i] & 0x1F);
		comp[1] = (comp[1] << 3) | (comp[1] >> 2);
        comp[2] = (comp[2] << 3) | (comp[2] >> 2);
        comp[3] = (comp[3] << 3) | (comp[3] >> 2);
		*pixels = (comp[0] << 24) + (comp[1] << 16) + (comp[2] << 8) + comp[3];
		if (i % 3 == 0 && i < 10)
			fprintf(stdout, "debug i = %zu | iterator = %02hhx %02hhx  | pixel = %#010x\n", i, iterator[i], iterator[i + 1], *pixels);
		i += 2;
		pixels++;
	}
}

void tga_process_15bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t i;
	unsigned char *iterator;
	unsigned char comp[3];

	i = 0;
	iterator = (unsigned char *)(tga->data + sizeof(t_tga_header));
	while (i < tga->width * tga->height * 2)
	{
        comp[0] = (iterator[i + 1] >> 2) & 0x1F;
        comp[1] = ((iterator[i + 1] << 3) & 0x1C) | ((iterator[i] >> 5) & 0x07);
        comp[2] = (iterator[i] & 0x1F);
		comp[0] = (comp[0] << 3) | (comp[0] >> 2);
        comp[1] = (comp[1] << 3) | (comp[1] >> 2);
        comp[2] = (comp[2] << 3) | (comp[2] >> 2);
		*pixels = (255 << 24) + (comp[0] << 16) + (comp[1] << 8) + comp[2];
		if (i % 3 == 0 && i < 10)
			fprintf(stdout, "debug i = %zu | iterator = %02hhx %02hhx  | pixel = %#010x\n", i, iterator[i], iterator[i + 1], *pixels);
		i += 2;
		pixels++;
	}
}

void tga_process_8bpp(t_tga_info *tga, unsigned int *pixels)
{
	size_t i;
	unsigned char *iterator;
	fprintf(stdout, "debug 8bpp!\n", NULL);
	i = 0;
	iterator = (unsigned char *)(tga->data + sizeof(t_tga_header));
	while (i < tga->width * tga->height)
	{
		// pixels[i] = (((iterator[i] & 0x000000ff)) | \
		// 			((iterator[i] & 0x0000ff00)) | \
		// 			((iterator[i] & 0x00ff0000)) | \
		// 			((iterator[i] & 0xff000000)));
		*pixels = (0 << 24) + (iterator[i] << 16) + (iterator[i] << 8) + iterator[i];
		pixels++;
		i++;
	}
}

unsigned int		*tga_process_pixels(t_tga_info *tga)
{
	unsigned int	*pix_data;

	pix_data = NULL;
	if (!(pix_data = malloc(tga->width * tga->height * sizeof(unsigned int))))
		return NULL;
	if (tga)
	{
		if (tga->depth == 32)
			tga_process_32bpp(tga, pix_data);
		else if (tga->depth == 24)
			tga_process_24bpp(tga, pix_data);
		else if (tga->depth == 16)
			tga_process_16bpp(tga, pix_data);
		else if (tga->depth == 15)
			tga_process_15bpp(tga, pix_data);
		else if (tga->depth == 8)
			tga_process_8bpp(tga, pix_data);
		else
		{
			free(pix_data);
			return (tga_error("Image has no valid BPP value!", tga->data));
		}
		free(tga->data);
		return (pix_data);
	}
	return (NULL);
}


// unsigned int *tga_process_pixels_24(t_tga_info *tga)
// {
// 	unsigned int *buffer;
// 	unsigned char *cursor_data;
// 	unsigned char *cursor_buffer;
// 	size_t	i;
// 	size_t 	j;

// 	i = 0;
// 	j = 0;

// 	// DEBUGGING
// 	size_t k = 0;

// 	if (!(buffer = malloc(tga->width * tga->height * 4))) // +1?
// 		return (tga_error("Could not create pixels buffer", tga->data));
// 	cursor_data = &tga->data[sizeof(t_tga_header)];
// 	cursor_buffer = (unsigned char*)buffer;
// 	while (i < tga->width * tga->height * 4)
// 	{
// 		fprintf(stdout, "p_data[%zu] = 0x%08X\n", k, (int)cursor_data[k]);
// 		cursor_buffer[i++] = cursor_data[j++];
// 		cursor_buffer[i++] = cursor_data[j++];
// 		cursor_buffer[i++] = cursor_data[j];
// 		cursor_buffer[i] = 0;
// 		i++;
// 		j++;
// 		fprintf(stdout, "n_buffer[%zu] = 0x%08X\n\n", k, buffer[k]);
// 		k++;
// 	}
// 	return buffer;
// }
