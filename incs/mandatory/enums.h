/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twang <twang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:12:52 by aascedu           #+#    #+#             */
/*   Updated: 2023/10/20 13:23:18 by twang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

/*---- typedef enums ---------------------------------------------------------*/

typedef enum e_tile			t_tile;
typedef enum e_keyerror		t_keyerror;
typedef enum e_keyassets	t_keyassets;
typedef enum e_keycode		t_keycode;

/*---- enums -----------------------------------------------------------------*/

enum e_tile
{
	empty	= ' ',
	space	= '0',
	wall	= '1',
	north	= 'N',
	south	= 'S',
	east	= 'E',
	west	= 'W',
	player	= 'P'
};

enum e_keyerror
{
	no_args,
	wrong_file,
	wrong_asset,
	wrong_texture,
	wrong_textures,
	wrong_color,
	wrong_colors,
	wrong_map,
	wrong_char,
	wrong_player
};

enum e_keyassets
{
	north_texture,
	south_texture,
	west_texture,
	east_texture,
	ceiling_color,
	floor_color,
	no_asset
};

# ifndef MACOS

enum e_keycode
{
	m_left_key	=	1,
	scroll_key	=	2,
	m_right_key	=	3,
	m_down_key	=	4,
	m_up_key	=	5,
	a_key		=	97,
	b_key		=	98,
	c_key		=	99,
	d_key		=	100,
	s_key		=	115,
	f_key		=	102,
	g_key		=	103,
	h_key		=	104,
	z_key		=	122,
	x_key		=	120,
	v_key		=	118,
	q_key		=	113,
	w_key		=	119,
	e_key		=	101,
	r_key		=	114,
	y_key		=	121,
	t_key		=	116,
	one_key		=	49,
	two_key		=	50,
	three_key	=	51,
	four_key	=	52,
	six_key		=	54,
	five_key	=	53,
	equal_key	=	61,
	nine_key	=	57,
	seven_key	=	55,
	minus_key	=	45,
	eight_key	=	56,
	zero_key	=	48,
	cbracket_key=	93,
	o_key		=	111,
	u_key		=	117,
	obracket_key=	91,
	i_key		=	105,
	p_key		=	112,
	enter_key	=	65293,
	l_key		=	108,
	j_key		=	106,
	quote_key	=	39,
	k_key		=	107,
	semico_key	=	59,
	pipe_key	=	92,
	comma_key	=	44,
	slash_key	=	47,
	n_key		=	110,
	m_key		=	109,
	dot_key		=	46,
	tab_key		=	65289,
	space_key	=	32,
	tilde_key	=	96,
	del_key		=	65288,
	esc_key		=	65307,
	left_key	=	65361,
	right_key	=	65363,
	down_key	=	65364,
	up_key		=	65362,
	ctrl_l_key	=	65507,
	ctrl_r_key	=	65508,
	maj_l_key	=	65505,
	maj_r_key	=	65506,
	alt_l_key	=	65513,
	alt_r_key	=	65514,
	majlock_key	=	65509
};

# else

enum e_keycode
{
	m_left_key	=	1,
	scroll_key	=	2,
	m_right_key	=	3,
	m_down_key	=	4,
	m_up_key	=	5,
	a_key		=	0,
	s_key		=	1,
	d_key		=	2,
	f_key		=	3,
	h_key		=	4,
	g_key		=	5,
	z_key		=	6,
	x_key		=	7,
	c_key		=	8,
	v_key		=	9,
	b_key		=	11,
	q_key		=	12,
	w_key		=	13,
	e_key		=	14,
	r_key		=	15,
	y_key		=	16,
	t_key		=	17,
	one_key		=	18,
	two_key		=	19,
	three_key	=	20,
	four_key	=	21,
	six_key		=	22,
	five_key	=	23,
	equal_key	=	24,
	nine_key	=	25,
	seven_key	=	26,
	minus_key	=	27,
	eight_key	=	28,
	zero_key	=	29,
	cbracket_key=	30,
	o_key		=	31,
	u_key		=	32,
	obracket_key=	33,
	i_key		=	34,
	p_key		=	35,
	enter_key	=	36,
	l_key		=	37,
	j_key		=	38,
	quote_key	=	39,
	k_key		=	40,
	semico_key	=	41,
	pipe_key	=	42,
	comma_key	=	43,
	slash_key	=	44,
	n_key		=	45,
	m_key		=	46,
	dot_key		=	47,
	tab_key		=	48,
	space_key	=	49,
	tilde_key	=	50,
	del_key		=	51,
	esc_key		=	53,
	left_key	=	123,
	right_key	=	124,
	down_key	=	125,
	up_key		=	126,
	ctrl_key	=	256,
	maj_l_key	=	257,
	maj_r_key	=	258,
	cmd_l_key	=	259,
	cmd_r_key	=	260,
	opt_l_key	=	261,
	opt_r_key	=	262,
	majlock_key	=	272,
	fn_key		=	279
};

# endif

#endif
