/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_longlong_unsigned.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 21:01:04 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:07 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_longlong_unsigned(unsigned long long nb)
{
	if (nb >= 10)
		if (ft_putnbr_longlong_unsigned(nb / 10) == -1)
			return (-1);
	return (ft_putchar(nb % 10 + '0'));
}
