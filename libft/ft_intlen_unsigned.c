/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 20:00:52 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:08:26 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_intlen_unsigned(unsigned int nbr)
{
	int		count;

	count = 1;
	while (nbr > 9)
	{
		++count;
		nbr /= 10;
	}
	return (count);
}
