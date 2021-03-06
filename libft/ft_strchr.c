/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:32:40 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:14 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char				*ft_strchr(const char *s, int c)
{
	size_t			len;
	unsigned char	tmp;

	if (s == NULL)
		return (NULL);
	tmp = (unsigned char)c;
	len = ft_strlen((char *)(uintptr_t)s);
	if (tmp == '\0')
		return ((char *)(uintptr_t)s + len);
	while (*s != '\0')
	{
		if (*s == tmp)
			return ((char *)(uintptr_t)s);
		s++;
	}
	return (NULL);
}
