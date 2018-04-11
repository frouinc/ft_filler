/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:07:13 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:55 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	size_t				count;
	unsigned char		*tmp;
	unsigned char		tmp_c;

	count = 0;
	if (s == NULL)
		return (NULL);
	tmp = (unsigned char *)(uintptr_t)s;
	tmp_c = (unsigned char)c;
	while (count < n)
	{
		if (*tmp == tmp_c)
			return ((void *)tmp);
		tmp++;
		++count;
	}
	return (NULL);
}
