/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_goal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 14:45:50 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:04 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_edge(t_data *data)
{
	int			edge;
	int			y;

	y = -1;
	edge = data->goalw.x;
	while (++y < data->map.size_y)
		if (data->map.shape[y][edge] == data->player
			|| data->map.shape[y][edge] == (data->player - 32))
			return (1);
	return (0);
}

static void		take_first_goal(t_data *data)
{
	int			y;
	int			x;
	t_pos		player;

	y = -1;
	while (++y < data->map.size_y)
	{
		x = -1;
		while (++x < data->map.size_x)
			if (data->map.shape[y][x] == (data->player - 32))
			{
				player.x = x;
				player.y = y;
			}
	}
	if (player.x < (data->map.size_x / 2))
		data->goalw.x = (data->map.size_x - 1);
	else
		data->goalw.x = 0;
	data->goalw.y = player.y;
}

static void		give_pos(t_data *data, int y, int x)
{
	data->goalt.x = x;
	data->goalt.y = y;
}

static void		take_nemesis(t_data *data)
{
	int			y;
	int			flag;
	int			x;
	char		c;

	flag = 0;
	if (data->player == 'o')
		c = 'X';
	else
		c = 'O';
	y = -1;
	while (++y < data->map.size_y)
	{
		x = -1;
		while (++x < data->map.size_x)
			if (data->map.shape[y][x] == c)
			{
				++flag;
				give_pos(data, y, x);
			}
	}
	if (flag == 0)
		give_pos(data, 0, 0);
}

void			get_goal(t_data *data)
{
	if (data->phase == 0)
	{
		take_nemesis(data);
		take_first_goal(data);
		++data->phase;
	}
	if (check_edge(data) == 1
		|| (data->map.shape[data->goalw.y][data->goalw.x] != '.'
		&& data->phase < 3))
	{
		if (data->phase == 1)
		{
			if (data->goalw.x == 0)
				data->goalw.x = (data->map.size_x - 1);
			else
				data->goalw.x = 0;
			++data->phase;
		}
		else
		{
			data->goalw.x = data->goalt.x;
			data->goalw.y = data->goalt.y;
		}
	}
}
