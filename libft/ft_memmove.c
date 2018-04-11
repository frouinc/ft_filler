/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:47:05 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:57 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	char		*tmp;

	if (dest == NULL || src == NULL)
		return (NULL);
	d = dest;
	s = src;
	if ((tmp = malloc((n + 1) * sizeof(char))) == NULL)
		return (NULL);
	tmp = ft_memcpy(tmp, s, n);
	d = ft_memcpy(d, tmp, n);
	free(tmp);
	return (d);
}
