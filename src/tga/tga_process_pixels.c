/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_pixels.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 11:01:19 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/15 18:28:40 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

static unsigned int 		*tga_process_pixels_32(t_tga_info *tga)
{
	unsigned int *buffer;
	size_t	i;
	char 	*tmp;

	i = 0;
	tmp = NULL;
	if (!(buffer = malloc(tga->width * tga->height * 4))) // +1?
		return (tga_error("Could not create pixels buffer", tga->data));
	memcpy(buffer, &tga->data[sizeof(t_tga_header)], tga->pixels_nbytes);
	while (i < tga->width * tga->height)
	{
		fprintf(stdout, "32p_buffer[%lu] = 0x%08X\n", i + 1, buffer[i]);
		tmp = (char*)&buffer[i];

		//if (alphabidule?)
		// *(tmp + 3) = 0xff - *(tmp + 3);
		//

		fprintf(stdout, "32n_buffer[%lu] = 0x%08X\n\n", i + 1, buffer[i]);
		i++;
	}
	return (buffer);
}

static unsigned int *tga_process_pixels_24(t_tga_info *tga)
{
	unsigned int *buffer;
	unsigned char *cursor_data;
	unsigned char *cursor_buffer;
	size_t	i;
	size_t 	j;

	i = 0;
	j = 0;

	// DEBUGGING
	size_t k = 0;

	if (!(buffer = malloc(tga->width * tga->height * 4))) // +1?
		return (tga_error("Could not create pixels buffer", tga->data));
	cursor_data = &tga->data[sizeof(t_tga_header)];
	cursor_buffer = (unsigned char*)buffer;
	while (i < tga->width * tga->height * 4)
	{
		fprintf(stdout, "p_data[%zu] = 0x%08X\n", k, (int)cursor_data[k]);
		cursor_buffer[i++] = cursor_data[j++];
		cursor_buffer[i++] = cursor_data[j++];
		cursor_buffer[i++] = cursor_data[j];
		cursor_buffer[i] = 0;
		i++;
		j++;
		fprintf(stdout, "n_buffer[%zu] = 0x%08X\n\n", k, buffer[k]);
		k++;
	}
	return buffer;
}

unsigned int		*tga_process_pixels(t_tga_info *tga,
										size_t *width,
										size_t *height)
{
	unsigned int	*pix_data;

	pix_data = NULL;
	if (tga && width && height)
	{
		if (tga->depth == 32)
			pix_data = tga_process_pixels_32(tga);
		else if (tga->depth == 24)
			pix_data = tga_process_pixels_24(tga);
		else if (tga->depth == 16)
			;
		else
			;


		// if (!(buffer = tga_dump_pixels(tga, buffer)))
		// 	return (tga_error("Error during pixels copy to buffer", tga->data));
		// if (tga_transform(buffer, tga->image_origin) != 0)
		// 	return (tga_error("Error during pixels transformation", tga->data));
		*width = tga->width;
		*height = tga->height;
		free(tga->data);
		return (pix_data);
	}
	return (NULL);
}
