/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:05:20 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:00 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		one_touch2(t_data *data, t_pos *pos, int y, int x)
{
	int			tmp;

	tmp = 0;
	if (data->piece.shape[y][x] == '*'
		&& (data->map.shape[pos->y + y][pos->x + x]
		== data->player
		|| data->map.shape[pos->y + y][pos->x + x]
		== (data->player - 32)))
		++tmp;
	if (data->piece.shape[y][x] == '*'
		&& data->map.shape[pos->y + y][pos->x + x] != '.'
		&& data->map.shape[pos->y + y][pos->x + x]
		!= data->player
		&& data->map.shape[pos->y + y][pos->x + x]
		!= (data->player - 32))
		return (-1);
	return (tmp);
}

static int		one_touch(t_data *data, t_pos *pos)
{
	int			y;
	int			x;
	int			flag;
	int			tmp;

	y = -1;
	flag = 0;
	while (++y < data->piece.size_y
		&& (pos->y + y) < data->map.size_y)
	{
		x = -1;
		while (++x < data->piece.size_x
			&& (pos->x + x) < data->map.size_x)
		{
			if ((tmp = one_touch2(data, pos, y, x)) == -1)
				return (-1);
			else
				flag += tmp;
		}
	}
	if (flag != 1)
		return (-1);
	return (flag);
}

static t_pos	test_piece(t_data *data, t_pos *pos_map, int x, int y)
{
	t_pos		tmp;
	t_pos		best;
	t_pos		error;

	error.x = -1;
	if (data->piece.shape[y][x] == '.')
		return (error);
	if ((pos_map->x - x) < 0 || (pos_map->y - y) < 0
		|| (pos_map->x + (data->piece.size_x - x)) > data->map.size_x
		|| (pos_map->y + (data->piece.size_y - y)) > data->map.size_y)
		return (error);
	tmp.x = pos_map->x - x;
	tmp.y = pos_map->y - y;
	if (one_touch(data, &tmp) == -1)
		return (error);
	best.x = tmp.x;
	best.y = tmp.y;
	return (best);
}

static void		try_piece(t_data *data, t_pos *pos, t_pos *best)
{
	int			y;
	int			x;
	t_pos		tmp;

	y = -1;
	while (++y < data->piece.size_y)
	{
		x = -1;
		while (++x < data->piece.size_x)
		{
			tmp = test_piece(data, pos, x, y);
			if (tmp.x != -1)
				get_best_pos(&tmp, best, &(data->goalw));
		}
	}
}

int				check_case(t_data *data, t_pos *best, int x, int y)
{
	t_pos		pos;

	if (data->map.shape[y][x] != data->player
		&& data->map.shape[y][x] != (data->player - 32))
		return (-1);
	pos.x = x;
	pos.y = y;
	best->x = -100;
	try_piece(data, &pos, best);
	return (0);
}
