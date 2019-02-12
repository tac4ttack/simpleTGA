/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_load_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:02:57 by fmessina          #+#    #+#             */
/*   Updated: 2019/02/12 20:16:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

static void    tga_print_header(t_tga_header *header, const char *target)
{
    fprintf(stdout,
            "\nTGA HEADER (%s) =\n"
            "\tid_length = %hhd\n\tcolor_map_type = %hhd\n\timage_type = %hhd"
            "\n\tfirst_entry_index = %hu\n\tcolor_map_length = %hu\n"
            "\tcolor_map_entry_size = %hhu\n\tx_origin = %hu\n\ty_origin = "
            "%hu\n\timage_width = %hu\n\timage_height = %hu\n"
            "\tpixel_depth = %hhu\n\timage_descriptor = %hhu\n",
            target,
            header->id_length,
            header->color_map_type,
            header->image_type,
            header->first_entry_index,
            header->color_map_length,
            header->color_map_entry_size,
            header->x_origin,
            header->y_origin,
            header->image_width,
            header->image_heigth,
            header->pixel_depth,
            header->image_descriptor);
}

unsigned int *tga_load_file(const char *target, size_t *width, size_t *height)
{
    t_tga_header    *target_header;
    size_t          target_size;
    unsigned int    *target_pixels;
    char            *target_data;

    if (target)
    {
        if (!(target_data = tga_process_file(target, &target_size)))
            return tga_error("Could not read target file", target_data);
        if (target_size <= sizeof(t_tga_header))
            return tga_error("Empty or corrupted TGA file", target_data);
        target_header = (t_tga_header*)target_data;
        tga_print_header(target_header, target);
        // checking image type support
        if (target_header->image_type == TGA_TYPE_RAW_TC)
        {
            if (target_header->pixel_depth == 32)
            {
                if (!(target_pixels = malloc(target_header->image_width \
                                            * target_header->image_heigth \
                                            * (target_header->pixel_depth / 8)
                                            )))
                        return tga_error("TGA file format not supported", target_data);

                    memcpy(target_pixels, \
                            (target_data + sizeof(t_tga_header)), \
                            (target_header->image_width \
                            * target_header->image_heigth \
                            * (target_header->pixel_depth / 8))
                            );
                    if (target_header->pixel_depth == 32)
                    {
                        int i = target_header->image_width * target_header->image_heigth;
                        while (i--)
                        {
                            target_pixels[i] = (
                                (target_pixels[i] & 0x000000ff) << 24
                                | (target_pixels[i] & 0x0000ff00) << 8
                                | (target_pixels[i] & 0x00ff0000) >> 8
                                | (target_pixels[i] & 0xff000000) >> 24
                                );
                        }
                        *width = target_header->image_width;
                        *height = target_header->image_heigth;
                        free(target_data);
                        target_data = NULL;
                        return target_pixels;
                    }
            }
            else if (target_header->pixel_depth == 24)
            {
                return tga_error("24 bits fuck", target_data);
            }
            else
            {
                return tga_error("Invalid color depth " \
                                    "(not a 32/24bits raw truecolor)", \
                                    target_data);
            }
        }
        else
        {
            return tga_error("Unsupported TGA image format " \
                                "(not a 32/24bits raw truecolor)", \
                                target_data);
        }
    }
    return NULL;
}
