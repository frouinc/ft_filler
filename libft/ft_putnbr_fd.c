/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:18:58 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:07 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		if (ft_putnbr_fd(((nb / 10) * -1), fd) == -1)
			return (-1);
		return (ft_putchar_fd((((nb % 10) * -1) + '0'), fd));
	}
	if (nb < 0)
	{
		if (ft_putchar_fd('-', fd) == -1)
			return (-1);
		nb = nb * -1;
	}
	if (nb >= 10)
		if (ft_putnbr_fd((nb / 10), fd) == -1)
			return (-1);
	return (ft_putchar_fd((nb % 10 + '0'), fd));
}
