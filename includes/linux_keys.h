/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linux_keys.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:17:53 by adalenco          #+#    #+#             */
/*   Updated: 2019/02/11 15:00:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINUX_KEYS_H
# define LINUX_KEYS_H

typedef	struct	s_key
{
	char			k_esc;
	char			k_la;
	char			k_ra;
	char			k_ua;
	char			k_da;
	char			k_a;
	char			k_b;
	char			k_c;
	char			k_d;
	char			k_e;
	char			k_f;
	char			k_g;
	char			k_h;
	char			k_i;
	char			k_j;
	char			k_k;
	char			k_l;
	char			k_m;
	char			k_n;
	char			k_o;
	char			k_p;
	char			k_q;
	char			k_r;
	char			k_s;
	char			k_t;
	char			k_u;
	char			k_v;
	char			k_w;
	char			k_x;
	char			k_y;
	char			k_z;
	char			k_0;
	char			k_1;
	char			k_2;
	char			k_3;
	char			k_4;
	char			k_5;
	char			k_6;
	char			k_7;
	char			k_8;
	char			k_9;
	char			k_n0;
	char			k_n1;
	char			k_n2;
	char			k_n3;
	char			k_n4;
	char			k_n5;
	char			k_n6;
	char			k_n7;
	char			k_n8;
	char			k_n9;
	char			k_nsla;
	char			k_nstr;
	char			k_nmin;
	char			k_nplu;
	char			k_nent;
	char			k_ndot;
	char			k_ndel;
	char			k_home;
	char			k_end;
	char			k_pgu;
	char			k_pgd;
	char			k_del;
	char			k_bsp;
	char			k_spc;
	char			k_lshi;
	char			k_rshi;
	char			k_lctrl;
	char			k_rctrl;
	char			k_lopt;
	char			k_ropt;
	char			k_com;
	char			k_dot;
	char			k_sla;
	char			k_scol;
	char			k_quo;
	char			k_lbra;
	char			k_rbra;
	char			k_bsla;
	char			k_dash;
	char			k_equ;
	char			k_apo;
	char			k_tab;
	char			k_caps;
	char			k_ret;
	char			k_fn;
	char			k_f1;
	char			k_f2;
	char			k_f3;
	char			k_f4;
	char			k_f5;
	char			k_f6;
	char			k_f7;
	char			k_f8;
	char			k_f9;
	char			k_f10;
	char			k_f11;
	char			k_f12;
	char			k_f13;
	char			k_f14;
	char			k_f15;
	char			k_f16;
	char			k_f17;
	char			k_f18;
	char			k_f19;
}				t_key;

/*
****	MACOS KEYS DEFINE	****
*/
# define K_ESC						65307
# define K_LA						65361
# define K_RA						65363
# define K_UA						65362
# define K_DA						65364
# define K_A						97
# define K_B						98
# define K_C						99
# define K_D						100
# define K_E						101
# define K_F						102
# define K_G						103
# define K_H						104
# define K_I						105
# define K_J						106
# define K_K						107
# define K_L						108
# define K_M						109
# define K_N						110
# define K_O						111
# define K_P						112
# define K_Q						113
# define K_R						114
# define K_S						115
# define K_T						116
# define K_U						117
# define K_V						118
# define K_W						119
# define K_X						120
# define K_Y						121
# define K_Z						122
# define K_0						48
# define K_1						49
# define K_2						50
# define K_3						51
# define K_4						52
# define K_5						53
# define K_6						54
# define K_7						55
# define K_8						56
# define K_9						57
# define K_N0						65438
# define K_N1						65436
# define K_N2						65433
# define K_N3						65435
# define K_N4						65430
# define K_N5						65437
# define K_N6						65432
# define K_N7						65429
# define K_N8						65431
# define K_N9						65434
# define K_NSLA						65455
# define K_NSTR						65450
# define K_NMIN						65453
# define K_NPLU						65451
# define K_NENT						65421
# define K_NDOT						65439
# define K_NDEL						65439
# define K_HOME						65360
# define K_END						65367
# define K_PGU						65365
# define K_PGD						65366
# define K_DEL						65535
# define K_BSP						65288
# define K_SPC						32
# define K_LSHI						65505
# define K_RSHI						65506
# define K_LCTRL					65507
# define K_RCTRL					65508
# define K_LOPT						65513
# define K_ROPT						65514
# define K_COM						44
# define K_DOT						46
# define K_SLA						47
# define K_SCOL						52
# define K_QUO						39
# define K_LBRA						91
# define K_RBRA						93
# define K_BSLA						92
# define K_DASH						45
# define K_EQU						61
# define K_APO						96
# define K_TAB						65289
# define K_CAPS						65509
# define K_RET						65293
# define K_FN						65383
# define K_F1						65470
# define K_F2						65471
# define K_F3						65472
# define K_F4						65473
# define K_F5						65474
# define K_F6						65475
# define K_F7						65476
# define K_F8						65477
# define K_F9						65478
# define K_F10						65479
# define K_F11						65480
# define K_F12						65481
# define K_F13						105
# define K_F14						107
# define K_F15						113
# define K_F16						106
# define K_F17						64
# define K_F18						79
# define K_F19						80

# define KP_ESC						env->mlx_keys->k_esc
# define KP_LA						env->mlx_keys->k_la
# define KP_RA						env->mlx_keys->k_ra
# define KP_UA						env->mlx_keys->k_ua
# define KP_DA						env->mlx_keys->k_da
# define KP_A						env->mlx_keys->k_a
# define KP_B						env->mlx_keys->k_b
# define KP_C						env->mlx_keys->k_c
# define KP_D						env->mlx_keys->k_d
# define KP_E						env->mlx_keys->k_e
# define KP_F						env->mlx_keys->k_f
# define KP_G						env->mlx_keys->k_g
# define KP_H						env->mlx_keys->k_h
# define KP_I						env->mlx_keys->k_i
# define KP_J						env->mlx_keys->k_j
# define KP_K						env->mlx_keys->k_k
# define KP_L						env->mlx_keys->k_l
# define KP_M						env->mlx_keys->k_m
# define KP_N						env->mlx_keys->k_n
# define KP_O						env->mlx_keys->k_o
# define KP_P						env->mlx_keys->k_p
# define KP_Q						env->mlx_keys->k_q
# define KP_R						env->mlx_keys->k_r
# define KP_S						env->mlx_keys->k_s
# define KP_T						env->mlx_keys->k_t
# define KP_U						env->mlx_keys->k_u
# define KP_V						env->mlx_keys->k_v
# define KP_W						env->mlx_keys->k_w
# define KP_X						env->mlx_keys->k_x
# define KP_Y						env->mlx_keys->k_y
# define KP_Z						env->mlx_keys->k_z
# define KP_0						env->mlx_keys->k_0
# define KP_1						env->mlx_keys->k_1
# define KP_2						env->mlx_keys->k_2
# define KP_3						env->mlx_keys->k_3
# define KP_4						env->mlx_keys->k_4
# define KP_5						env->mlx_keys->k_5
# define KP_6						env->mlx_keys->k_6
# define KP_7						env->mlx_keys->k_7
# define KP_8						env->mlx_keys->k_8
# define KP_9						env->mlx_keys->k_9
# define KP_N0						env->mlx_keys->k_n0
# define KP_N1						env->mlx_keys->k_n1
# define KP_N2						env->mlx_keys->k_n2
# define KP_N3						env->mlx_keys->k_n3
# define KP_N4						env->mlx_keys->k_n4
# define KP_N5						env->mlx_keys->k_n5
# define KP_N6						env->mlx_keys->k_n6
# define KP_N7						env->mlx_keys->k_n7
# define KP_N8						env->mlx_keys->k_n8
# define KP_N9						env->mlx_keys->k_n9
# define KP_NSLA					env->mlx_keys->k_nsla
# define KP_NSTR					env->mlx_keys->k_nstr
# define KP_NMIN					env->mlx_keys->k_nmin
# define KP_NPLU					env->mlx_keys->k_nplu
# define KP_NENT					env->mlx_keys->k_nent
# define KP_NDOT					env->mlx_keys->k_ndot
# define KP_NDEL					env->mlx_keys->k_ndel
# define KP_HOME					env->mlx_keys->k_home
# define KP_END						env->mlx_keys->k_end
# define KP_PGU						env->mlx_keys->k_pgu
# define KP_PGD						env->mlx_keys->k_pgd
# define KP_DEL						env->mlx_keys->k_del
# define KP_BSP						env->mlx_keys->k_bsp
# define KP_SPC						env->mlx_keys->k_spc
# define KP_LSHI					env->mlx_keys->k_lshi
# define KP_RSHI					env->mlx_keys->k_rshi
# define KP_LCTRL					env->mlx_keys->k_lctrl
# define KP_RCTRL					env->mlx_keys->k_rctrl
# define KP_LOPT					env->mlx_keys->k_lopt
# define KP_ROPT					env->mlx_keys->k_ropt
# define KP_COM						env->mlx_keys->k_com
# define KP_DOT						env->mlx_keys->k_dot
# define KP_SLA						env->mlx_keys->k_sla
# define KP_SCOL					env->mlx_keys->k_scol
# define KP_QUO						env->mlx_keys->k_quo
# define KP_LBRA					env->mlx_keys->k_lbra
# define KP_RBRA					env->mlx_keys->k_rbra
# define KP_BSLA					env->mlx_keys->k_bsla
# define KP_DASH					env->mlx_keys->k_dash
# define KP_EQU						env->mlx_keys->k_equ
# define KP_APO						env->mlx_keys->k_apo
# define KP_TAB						env->mlx_keys->k_tab
# define KP_CAP						env->mlx_keys->k_cap
# define KP_RET						env->mlx_keys->k_ret
# define KP_FN						env->mlx_keys->k_fn
# define KP_F1						env->mlx_keys->k_f1
# define KP_F2						env->mlx_keys->k_f2
# define KP_F3						env->mlx_keys->k_f3
# define KP_F4						env->mlx_keys->k_f4
# define KP_F5						env->mlx_keys->k_f5
# define KP_F6						env->mlx_keys->k_f6
# define KP_F7						env->mlx_keys->k_f7
# define KP_F8						env->mlx_keys->k_f8
# define KP_F9						env->mlx_keys->k_f9
# define KP_F10						env->mlx_keys->k_f10
# define KP_F11						env->mlx_keys->k_f11
# define KP_F12						env->mlx_keys->k_f12
# define KP_F13						env->mlx_keys->k_f13
# define KP_F14						env->mlx_keys->k_f14
# define KP_F15						env->mlx_keys->k_f15
# define KP_F16						env->mlx_keys->k_f16
# define KP_F17						env->mlx_keys->k_f17
# define KP_F18						env->mlx_keys->k_f18
# define KP_F19						env->mlx_keys->k_f19

#endif
