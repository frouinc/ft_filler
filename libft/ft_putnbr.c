/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:50:17 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:08 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		if (ft_putnbr((nb / 10) * -1) == -1)
			return (-1);
		return (ft_putchar(((nb % 10) * -1) + '0'));
	}
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = nb * -1;
	}
	if (nb >= 10)
		if (ft_putnbr(nb / 10) == -1)
			return (-1);
	return (ft_putchar(nb % 10 + '0'));
}
