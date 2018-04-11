/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 16:57:56 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:35:53 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void				delete_piece(t_shape *piece)
{
	int				y;

	if (piece->shape != NULL)
	{
		y = -1;
		while (++y < piece->size_y)
			free(piece->shape[y]);
		free(piece->shape);
	}
}

void				delete_map(t_shape *map)
{
	int				y;

	if (map->shape != NULL)
	{
		y = -1;
		while (++y < map->size_y)
		{
			if (map->shape[y])
				free(map->shape[y]);
		}
		free(map->shape);
	}
}
