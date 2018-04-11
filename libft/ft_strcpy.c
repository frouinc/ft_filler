/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:43:20 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:16 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpy(char *dest, const char *src)
{
	int		count;

	if (dest == NULL || src == NULL)
		return (NULL);
	count = -1;
	while (src[++count] != '\0')
		dest[count] = src[count];
	dest[count] = '\0';
	return (dest);
}
