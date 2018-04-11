/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:21:43 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:06 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	move_piece(t_shape *piece)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y + piece->offset.y < piece->size_y)
	{
		pos.x = 0;
		while (pos.x + piece->offset.x < piece->size_x)
		{
			piece->shape[pos.y][pos.x] =
			piece->shape[pos.y + piece->offset.y][pos.x + piece->offset.x];
			pos.x++;
		}
		while (pos.x < piece->size_x)
			piece->shape[pos.y][pos.x++] = 0;
		pos.y++;
	}
	while (pos.y < piece->size_y)
		free(piece->shape[pos.y++]);
	piece->size_x -= piece->offset.x;
	piece->size_y -= piece->offset.y;
	return (1);
}

static int	clear_piece(t_shape *piece)
{
	t_pos	pos;
	int		flag;

	pos.y = 0;
	flag = 0;
	while (pos.y < piece->size_y)
	{
		pos.x = 0;
		while (pos.x < piece->size_x)
		{
			if (piece->shape[pos.y][pos.x] == '*')
			{
				if (flag == 0)
					piece->offset.y = pos.y;
				flag = 1;
				if (pos.x < piece->offset.x)
					piece->offset.x = pos.x;
				break ;
			}
			pos.x++;
		}
		pos.y++;
	}
	move_piece(piece);
	return (1);
}

static int	clear_piece_out(t_shape *piece)
{
	t_pos	pos;
	int		widest;
	int		highest;

	pos.y = 0;
	widest = read_piece_widest(piece);
	highest = read_piece_highest(piece);
	while (pos.y <= highest)
	{
		pos.x = 0;
		while (pos.x <= widest)
			pos.x++;
		while (pos.x < piece->size_x)
			piece->shape[pos.y][pos.x++] = 0;
		pos.y++;
	}
	while (pos.y < piece->size_y)
		free(piece->shape[pos.y++]);
	piece->size_y = highest + 1;
	piece->size_x = widest + 1;
	return (0);
}

int			read_piece(char *line, t_shape *piece)
{
	int		i;

	i = 6;
	piece->size_y = ft_atoi(&(line[i]));
	while (line[i] != ' ')
		i++;
	i++;
	piece->size_x = ft_atoi(&(line[i]));
	i = 0;
	if ((piece->shape = malloc(piece->size_y * sizeof(char*))) == NULL)
		return (-1);
	while (i < piece->size_y)
	{
		get_next_line(0, &line);
		if ((piece->shape[i] = ft_strdup(line)) == NULL)
			return (-1);
		i++;
	}
	piece->offset.x = piece->size_x;
	piece->offset.y = 0;
	clear_piece(piece);
	clear_piece_out(piece);
	return (0);
}
