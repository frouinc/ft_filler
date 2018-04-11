/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_graph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 20:02:50 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:04 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void				display(t_data *data)
{
	int					y;
	int					x;

	y = -1;
	ft_putstr_fd("P1 = ", 2);
	ft_putstr_fd(BLUE"X"RESET, 2);
	ft_putstr_fd(" P2 = ", 2);
	ft_putstr_fd(RED"O"RESET, 2);
	ft_putstr_fd(" Neutral zone = ", 2);
	ft_putstr_fd(WHITE"[]\n"RESET, 2);
	while (++y < data->map.size_y)
	{
		x = -1;
		while (++x < data->map.size_x)
		{
			if (data->map.shape[y][x] == '.')
				ft_putstr_fd(WHITE"."RESET, 2);
			else if (data->map.shape[y][x] == 'x'
				|| data->map.shape[y][x] == 'X')
				ft_putstr_fd(RED"X"RESET, 2);
			else
				ft_putstr_fd(BLUE"O"RESET, 2);
		}
		ft_putstr_fd("\n", 2);
	}
}

int						main(void)
{
	t_data				data;

	data.player = '\0';
	data.map.shape = NULL;
	data.piece.shape = NULL;
	data.phase = 0;
	while (read_info(&data) == 0)
	{
		ft_putstr_fd(TCLN, 2);
		display(&data);
		if (play_game(&data) == -1)
			return (-1);
	}
	delete_piece(&(data.piece));
	delete_map(&(data.map));
	return (0);
}
