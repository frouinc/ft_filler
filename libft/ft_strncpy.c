/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:07:21 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:27 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		count;

	count = 0;
	if (dest == NULL || src == NULL)
		return (NULL);
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		++count;
	}
	while (count < n)
	{
		dest[count] = '\0';
		++count;
	}
	return (dest);
}
