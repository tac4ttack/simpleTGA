/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:03:00 by fmessina          #+#    #+#             */
/*   Updated: 2019/07/01 15:34:19 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga.h"

static void		memdel(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

bool			tga_berror(const char *message, t_tga *trash)
{
	if (trash)
	{
		memdel((void**)(&trash->data));
		memdel((void**)(&trash->pixels));
		memdel((void**)(&trash));
	}
	fprintf(stderr, "TGA Loading error: %s\n", message);
	return (false);
}

void			*tga_error(const char *message, t_tga *trash)
{
	if (trash)
	{
		memdel((void**)(&trash->data));
		memdel((void**)(&trash->pixels));
		memdel((void**)(&trash));
	}
	fprintf(stderr, "TGA Loading error: %s\n", message);
	return (NULL);
}
