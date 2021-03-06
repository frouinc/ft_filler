/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:34:33 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:08:21 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tab(char ***tab)
{
	int	i;

	i = -1;
	if (tab)
	{
		while ((*tab)[++i])
			free((*tab)[i]);
		free(*tab);
		*tab = NULL;
	}
}
