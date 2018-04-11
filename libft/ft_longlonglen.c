/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 20:59:33 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:49 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_longlonglen(long long nbr)
{
	int		count;

	count = 1;
	if (nbr < 0)
	{
		++count;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		++count;
		nbr /= 10;
	}
	return (count);
}
