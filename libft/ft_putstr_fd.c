/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:13:06 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:09 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr_fd(char const *s, int fd)
{
	if (s != NULL)
		return ((int)write(fd, s, ft_strlen((char *)(uintptr_t)s)));
	return (1);
}
