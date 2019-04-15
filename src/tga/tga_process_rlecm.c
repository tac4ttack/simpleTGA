/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_process_rlecm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 12:23:01 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/10 13:53:39 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser.h"

void	tga_process_rlecm(t_tga_info *tga, unsigned int *pix_data)
{
	(void)tga;
	tga_error("Sorry, color mapped TGA file are not supported yet!", pix_data);
}
