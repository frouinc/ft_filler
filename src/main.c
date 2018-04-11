/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 15:37:54 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/30 13:36:04 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int						main(void)
{
	t_data				data;

	data.player = '\0';
	data.map.shape = NULL;
	data.piece.shape = NULL;
	data.phase = 0;
	while (read_info(&data) == 0)
	{
		if (play_game(&data) == -1)
			return (-1);
	}
	delete_piece(&(data.piece));
	delete_map(&(data.map));
	return (0);
}
