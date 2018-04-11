/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:24:14 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:25 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int		size_dest;
	int		count;

	if (dest == NULL || src == NULL)
		return (NULL);
	count = 0;
	while (dest[count] != '\0')
		++count;
	size_dest = count;
	count = -1;
	while (src[++count] != '\0' && n > 0)
	{
		dest[size_dest + count] = src[count];
		--n;
	}
	dest[size_dest + count] = '\0';
	return (dest);
}
