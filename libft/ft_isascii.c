/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:18:18 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:08:43 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
