/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:32:39 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:52:30 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_puttab_fd(char **tab, int fd)
{
	int		count;

	count = -1;
	if (tab == NULL)
		return (0);
	while (tab[++count] != NULL)
		if (ft_putendl_fd(tab[count], fd) == -1)
			return (-1);
	return (1);
}
