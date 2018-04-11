/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:37:40 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:42:11 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		read_player(char *line, char *player, t_data *data)
{
	if (line[10] != '1' && line[10] != '2')
		filler_error(data, line, "Bad player: Need player 1 or 2");
	if (line[10] == '1')
		*player = 'o';
	else
		*player = 'x';
}

static void		map(t_data *data, char *line)
{
	if (data->map.shape != NULL)
		delete_map(&(data->map));
	read_map(line, &(data->map), data);
}

static void		piece(t_data *data, char *line)
{
	if (data->piece.shape != NULL)
		delete_piece(&(data->piece));
	read_piece(line, (&data->piece));
	if (data->piece.size_x == 1 && data->piece.size_y == 1
		&& data->piece.shape[0][0] == 0)
		filler_error(data, line, "No content in piece");
}

int				read_info(t_data *data)
{
	char		*line;
	int			error;

	while ((error = get_next_line(0, &line)))
	{
		if (error == -1)
			filler_error(data, line, "Malloc Error");
		if (data->player == '\0' && ft_strstr(line, "filler"))
			read_player(line, &(data->player), data);
		else if (ft_strstr(line, "Plateau"))
			map(data, line);
		else if (ft_strstr(line, "Piece"))
		{
			piece(data, line);
			return (0);
		}
		else
			filler_error(data, line, "Wrong input");
	}
	return (0);
}
