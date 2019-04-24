/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 11:03:00 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/24 13:06:16 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simpleTGA.h"

static void memdel(void **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

bool	tga_berror(const char *message, t_tga *trash)
{
	if (trash)
	{
		(void)trash;
	// 	memdel((void**)(&trash->data));
	// 	memdel((void**)(&trash->pixels));
	// 	memdel((void**)(&trash));
	}
	fprintf(stderr, "TGA Loading error: %s\n", message);
	return (false);
}

void	*tga_error(const char *message, t_tga *trash)
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
