/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:38:01 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:12 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_shape
{
	int				size_x;
	int				size_y;
	t_pos			offset;
	char			**shape;
}					t_shape;

typedef struct		s_data
{
	t_shape			map;
	t_shape			piece;
	char			player;
	struct s_pos	goalw;
	struct s_pos	goalt;
	int				phase;
}					t_data;

/*
** read_info.c
*/

int					read_info(t_data *data);

/*
** read_table.c
*/

void				read_map(char *line, t_shape *map, t_data *data);

/*
** check_error.c
*/

int					test_map_size(char *line);
int					test_map_content(char *line, t_shape *map);
int					test_piece_size(char *line);
int					test_piece_content(char *line, t_shape *piece);
void				filler_error(t_data *data, char *line, char *str);

/*
** play_game.c
*/

int					play_game(t_data *data);
void				get_best_pos(t_pos *tmp, t_pos *best, t_pos *goalw);

/*
** take_goal.c
*/

void				get_goal(t_data *data);

/*
** check_case.c
*/

int					check_case(t_data *data, t_pos *best, int x, int y);

/*
** delete.c
*/

void				delete_piece(t_shape *piece);
void				delete_map(t_shape *map);

/*
** read_piece.c
*/

int					read_piece(char *line, t_shape *piece);

/*
** read_piece2.c
*/

int					read_piece_widest(t_shape *piece);
int					read_piece_highest(t_shape *piece);

#endif
