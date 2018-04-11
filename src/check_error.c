/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:34:20 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:03 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			filler_error(t_data *data, char *line, char *str)
{
	delete_piece(&(data->piece));
	delete_map(&(data->map));
	if (line != NULL)
		free(line);
	if (str)
		ft_putendl(str);
	exit(EXIT_FAILURE);
}

int				test_piece_content(char *line, t_shape *piece)
{
	int			y;

	y = -1;
	while (line[++y] != '\0')
		if (line[y] != '.' && line[y] != '*')
			return (-1);
	if (y != piece->size_x)
		return (-1);
	return (0);
}

int				test_piece_size(char *line)
{
	int			y;

	y = 0;
	while (!(line[y] >= '0' && line[y] <= '9') && line[y] != '\0')
		++y;
	if (y != 6)
		return (-1);
	while ((line[y] >= '0' && line[y] <= '9') && line[y] != '\0')
		++y;
	if (line[y] != ' ')
		return (-1);
	++y;
	if (line[y] < '0' || line[y] > '9')
		return (-1);
	return (0);
}

int				test_map_content(char *line, t_shape *map)
{
	int			y;
	int			x;

	y = -1;
	while (++y < 3 && line[y] != '\0')
		if (line[y] < '0' && line[y] > '9')
			return (-1);
	if (line[y] != ' ')
		return (-1);
	x = 0;
	while (line[++y] != '\0')
	{
		++x;
		if (line[y] != '.' && line[y] != 'x' && line[y] != 'X'
			&& line[y] != 'o' && line[y] != 'O')
			return (-1);
	}
	if (x != map->size_x)
		return (-1);
	return (0);
}

int				test_map_size(char *line)
{
	int			y;

	y = 0;
	while (line[y] != '\0' && !(line[y] >= '0' && line[y] <= '9'))
		++y;
	if (y != 8)
		return (-1);
	while (line[y] != '\0' && (line[y] >= '0' && line[y] <= '9'))
		++y;
	if (line[y] != ' ')
		return (-1);
	++y;
	if (line[y] < '0' || line[y] > '9')
		return (-1);
	return (0);
}
