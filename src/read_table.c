/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:26:03 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:42:58 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		test_map(t_shape *map)
{
	int			x;
	int			y;
	int			flag_o;
	int			flag_x;

	y = 0;
	flag_o = 0;
	flag_x = 0;
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			if (map->shape[y][x] == 'X')
				flag_x++;
			if (map->shape[y][x] == 'O')
				flag_o++;
			x++;
		}
		y++;
	}
	if (flag_x == 0 || flag_o == 0)
		return (0);
	return (1);
}

static void		get_map_size(char *line, t_shape *map, t_data *data)
{
	int			y;

	if (test_map_size(line) == -1)
		filler_error(data, line, "Need: \"Plateau nbr nbr:\"");
	y = 8;
	map->size_y = ft_atoi(&(line[y]));
	while (line[y] != ' ')
		y++;
	map->size_x = ft_atoi(&(line[y + 1]));
	if ((map->shape = malloc((unsigned long)map->size_y * sizeof(char *)))
		== NULL)
		filler_error(data, line, "Malloc Error");
	y = 0;
	while (y < map->size_y)
	{
		map->shape[y] = NULL;
		y++;
	}
	free(line);
}

void			read_map(char *line, t_shape *map, t_data *data)
{
	int			y;

	get_map_size(line, map, data);
	if (get_next_line(0, &line) == -1)
		filler_error(data, line, "Malloc Error");
	free(line);
	y = 0;
	while (y < map->size_y)
	{
		if (get_next_line(0, &line) == -1)
			filler_error(data, line, "Malloc Error");
		if (test_map_content(line, map) == -1)
			filler_error(data, line, "Bad Board");
		if ((map->shape[y] = ft_strdup(line + 4)) == NULL)
			filler_error(data, line, "Malloc Error");
		free(line);
		y++;
	}
	if (test_map(map) == 0)
		filler_error(data, NULL, "Invalid starting point");
}
