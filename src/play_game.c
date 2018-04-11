/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:37:47 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:05 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			get_best_pos(t_pos *tmp, t_pos *best, t_pos *goalw)
{
	int			path1;
	int			path2;

	if (best->x == -420)
	{
		best->x = tmp->x;
		best->y = tmp->y;
	}
	else
	{
		path1 = ft_abs(tmp->x - goalw->x) + ft_abs(tmp->y - goalw->y);
		path2 = ft_abs(best->x - goalw->x) + ft_abs(best->y - goalw->y);
		if (path1 < path2)
		{
			best->x = tmp->x;
			best->y = tmp->y;
		}
	}
}

static int		print_best_pos(t_data *data, t_pos *best)
{
	ft_printf("%d %d\n", (best->y - data->piece.offset.y),
						(best->x - data->piece.offset.x));
	return (0);
}

int				play_game(t_data *data)
{
	int			y;
	int			x;
	t_pos		best;
	t_pos		tmp;

	get_goal(data);
	best.x = -420;
	y = -1;
	while (++y < data->map.size_y)
	{
		x = -1;
		while (++x < data->map.size_x)
		{
			if (check_case(data, &tmp, x, y) == 0)
				get_best_pos(&tmp, &best, &(data->goalw));
		}
	}
	if (print_best_pos(data, &best) == -1)
		return (-1);
	return (0);
}
