/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:39:47 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:10 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putstr(const char *s)
{
	if (s != NULL)
		return ((int)write(1, s, ft_strlen((char *)(uintptr_t)s)));
	return (-1);
}
