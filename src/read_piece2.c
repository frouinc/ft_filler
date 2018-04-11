/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrillef <cyrillef@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 18:23:13 by cyrillef          #+#    #+#             */
/*   Updated: 2017/10/30 13:36:06 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			read_piece_widest(t_shape *piece)
{
	int		size;
	int		tmp;
	t_pos	pos;

	pos.y = 0;
	size = 0;
	tmp = piece->size_x;
	while (pos.y < piece->size_y)
	{
		pos.x = 0;
		while (pos.x < piece->size_x)
		{
			if (piece->shape[pos.y][pos.x] == '*')
				tmp = pos.x;
			pos.x++;
		}
		if (tmp > size)
			size = tmp;
		pos.y++;
	}
	return (size);
}

int			read_piece_highest(t_shape *piece)
{
	int		size;
	int		tmp;
	t_pos	pos;

	pos.x = 0;
	size = 0;
	tmp = piece->size_y;
	while (pos.x < piece->size_x)
	{
		pos.y = 0;
		while (pos.y < piece->size_y)
		{
			if (piece->shape[pos.y][pos.x] == '*')
				tmp = pos.y;
			pos.y++;
		}
		if (tmp > size)
			size = tmp;
		pos.x++;
	}
	return (size);
}
