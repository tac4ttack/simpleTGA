/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key_press.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:37:50 by fmessina          #+#    #+#             */
/*   Updated: 2019/04/09 15:24:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_tga_parser_tester.h"

int	mlx_key_press(int key, t_env *env)
{
	(key == K_ESC ? env->mlx_keys->k_esc = 1 : 0);
	(key == K_LA ? env->mlx_keys->k_la = 1 : 0);
	(key == K_RA ? env->mlx_keys->k_ra = 1 : 0);
	(key == K_UA ? env->mlx_keys->k_ua = 1 : 0);
	(key == K_DA ? env->mlx_keys->k_da = 1 : 0);
	(key == K_A ? env->mlx_keys->k_a = 1 : 0);
	(key == K_B ? env->mlx_keys->k_b = 1 : 0);
	(key == K_C ? env->mlx_keys->k_c = 1 : 0);
	(key == K_D ? env->mlx_keys->k_d = 1 : 0);
	(key == K_E ? env->mlx_keys->k_e = 1 : 0);
	(key == K_F ? env->mlx_keys->k_f = 1 : 0);
	(key == K_G ? env->mlx_keys->k_g = 1 : 0);
	(key == K_H ? env->mlx_keys->k_h = 1 : 0);
	(key == K_I ? env->mlx_keys->k_i = 1 : 0);
	(key == K_I ? invert_image_alpha(env->target_img_data, \
									env->target_img_size[0], \
									env->target_img_size[1]) : 0);
	(key == K_J ? env->mlx_keys->k_j = 1 : 0);
	(key == K_K ? env->mlx_keys->k_k = 1 : 0);
	(key == K_L ? env->mlx_keys->k_l = 1 : 0);
	(key == K_M ? env->mlx_keys->k_m = 1 : 0);
	(key == K_N ? env->mlx_keys->k_n = 1 : 0);
	(key == K_O ? env->mlx_keys->k_o = 1 : 0);
	(key == K_P ? env->mlx_keys->k_p = 1 : 0);
	(key == K_Q ? env->mlx_keys->k_q = 1 : 0);
	(key == K_R ? env->mlx_keys->k_r = 1 : 0);
	(key == K_S ? env->mlx_keys->k_s = 1 : 0);
	(key == K_T ? env->mlx_keys->k_t = 1 : 0);
	(key == K_U ? env->mlx_keys->k_u = 1 : 0);
	(key == K_V ? env->mlx_keys->k_v = 1 : 0);
	(key == K_W ? env->mlx_keys->k_w = 1 : 0);
	(key == K_X ? env->mlx_keys->k_x = 1 : 0);
	(key == K_Y ? env->mlx_keys->k_y = 1 : 0);
	(key == K_Z ? env->mlx_keys->k_z = 1 : 0);
	(key == K_0 ? env->mlx_keys->k_0 = 1 : 0);
	(key == K_1 ? env->mlx_keys->k_1 = 1 : 0);
	(key == K_2 ? env->mlx_keys->k_2 = 1 : 0);
	(key == K_3 ? env->mlx_keys->k_3 = 1 : 0);
	(key == K_4 ? env->mlx_keys->k_4 = 1 : 0);
	(key == K_5 ? env->mlx_keys->k_5 = 1 : 0);
	(key == K_6 ? env->mlx_keys->k_6 = 1 : 0);
	(key == K_7 ? env->mlx_keys->k_7 = 1 : 0);
	(key == K_8 ? env->mlx_keys->k_8 = 1 : 0);
	(key == K_9 ? env->mlx_keys->k_9 = 1 : 0);
	(key == K_N0 ? env->mlx_keys->k_n0 = 1 : 0);
	(key == K_N1 ? env->mlx_keys->k_n1 = 1 : 0);
	(key == K_N2 ? env->mlx_keys->k_n2 = 1 : 0);
	(key == K_N3 ? env->mlx_keys->k_n3 = 1 : 0);
	(key == K_N4 ? env->mlx_keys->k_n4 = 1 : 0);
	(key == K_N5 ? env->mlx_keys->k_n5 = 1 : 0);
	(key == K_N6 ? env->mlx_keys->k_n6 = 1 : 0);
	(key == K_N7 ? env->mlx_keys->k_n7 = 1 : 0);
	(key == K_N8 ? env->mlx_keys->k_n8 = 1 : 0);
	(key == K_N9 ? env->mlx_keys->k_n9 = 1 : 0);
	(key == K_NSLA ? env->mlx_keys->k_nsla = 1 : 0);
	(key == K_NSTR ? env->mlx_keys->k_nstr = 1 : 0);
	(key == K_NMIN ? env->mlx_keys->k_nmin = 1 : 0);
	(key == K_NPLU ? env->mlx_keys->k_nplu = 1 : 0);
	(key == K_NENT ? env->mlx_keys->k_nent = 1 : 0);
	(key == K_NDOT ? env->mlx_keys->k_ndot = 1 : 0);
	(key == K_NEQU ? env->mlx_keys->k_nequ = 1 : 0);
	(key == K_NDEL ? env->mlx_keys->k_ndel = 1 : 0);
	(key == K_HOME ? env->mlx_keys->k_home = 1 : 0);
	(key == K_END ? env->mlx_keys->k_end = 1 : 0);
	(key == K_PGU ? env->mlx_keys->k_pgu = 1 : 0);
	(key == K_PGD ? env->mlx_keys->k_pgd = 1 : 0);
	(key == K_DEL ? env->mlx_keys->k_del = 1 : 0);
	(key == K_BSP ? env->mlx_keys->k_bsp = 1 : 0);
	(key == K_SPC ? env->mlx_keys->k_spc = 1 : 0);
	(key == K_LSHI ? env->mlx_keys->k_lshi = 1 : 0);
	(key == K_RSHI ? env->mlx_keys->k_rshi = 1 : 0);
	(key == K_LCTRL ? env->mlx_keys->k_lctrl = 1 : 0);
	(key == K_RCTRL ? env->mlx_keys->k_rctrl = 1 : 0);
	(key == K_LOPT ? env->mlx_keys->k_lopt = 1 : 0);
	(key == K_ROPT ? env->mlx_keys->k_ropt = 1 : 0);
	(key == K_LCMD ? env->mlx_keys->k_lcmd = 1 : 0);
	(key == K_RCMD ? env->mlx_keys->k_rcmd = 1 : 0);
	(key == K_COM ? env->mlx_keys->k_com = 1 : 0);
	(key == K_DOT ? env->mlx_keys->k_dot = 1 : 0);
	(key == K_SLA ? env->mlx_keys->k_sla = 1 : 0);
	(key == K_SCOL ? env->mlx_keys->k_scol = 1 : 0);
	(key == K_QUO ? env->mlx_keys->k_quo = 1 : 0);
	(key == K_LBRA ? env->mlx_keys->k_lbra = 1 : 0);
	(key == K_RBRA ? env->mlx_keys->k_rbra = 1 : 0);
	(key == K_BSLA ? env->mlx_keys->k_bsla = 1 : 0);
	(key == K_DASH ? env->mlx_keys->k_dash = 1 : 0);
	(key == K_EQU ? env->mlx_keys->k_equ = 1 : 0);
	(key == K_APO ? env->mlx_keys->k_apo = 1 : 0);
	(key == K_TAB ? env->mlx_keys->k_tab = 1 : 0);
	(key == K_CAPS ? env->mlx_keys->k_caps = 1 : 0);
	(key == K_RET ? env->mlx_keys->k_ret = 1 : 0);
	(key == K_FN ? env->mlx_keys->k_fn = 1 : 0);
	(key == K_F1 ? env->mlx_keys->k_f1 = 1 : 0);
	(key == K_F2 ? env->mlx_keys->k_f2 = 1 : 0);
	(key == K_F3 ? env->mlx_keys->k_f3 = 1 : 0);
	(key == K_F4 ? env->mlx_keys->k_f4 = 1 : 0);
	(key == K_F5 ? env->mlx_keys->k_f5 = 1 : 0);
	(key == K_F6 ? env->mlx_keys->k_f6 = 1 : 0);
	(key == K_F7 ? env->mlx_keys->k_f7 = 1 : 0);
	(key == K_F8 ? env->mlx_keys->k_f8 = 1 : 0);
	(key == K_F9 ? env->mlx_keys->k_f9 = 1 : 0);
	(key == K_F10 ? env->mlx_keys->k_f10 = 1 : 0);
	(key == K_F11 ? env->mlx_keys->k_f11 = 1 : 0);
	(key == K_F12 ? env->mlx_keys->k_f12 = 1 : 0);
	(key == K_F13 ? env->mlx_keys->k_f13 = 1 : 0);
	(key == K_F14 ? env->mlx_keys->k_f14 = 1 : 0);
	(key == K_F15 ? env->mlx_keys->k_f15 = 1 : 0);
	(key == K_F16 ? env->mlx_keys->k_f16 = 1 : 0);
	(key == K_F17 ? env->mlx_keys->k_f17 = 1 : 0);
	(key == K_F18 ? env->mlx_keys->k_f18 = 1 : 0);
	(key == K_F19 ? env->mlx_keys->k_f19 = 1 : 0);

	return (0);
}
