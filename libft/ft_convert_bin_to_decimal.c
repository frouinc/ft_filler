/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bin_to_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 15:54:36 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:08:18 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_convert_bin_to_decimal(char *bin)
{
	int		count;
	int		count2;
	double	tmp;
	int		decimal;

	decimal = 0;
	count = (int)ft_strlen(bin);
	count2 = 0;
	while (--count >= 0)
	{
		tmp = ft_pow((double)2, (double)count);
		decimal += (bin[count2] - '0') * (int)tmp;
		++count2;
	}
	return (decimal);
}
