/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:49:57 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:24 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*str;

	if (s != NULL && (*f) != NULL)
	{
		if ((str = malloc((ft_strlen((char *)(uintptr_t)s) + 1)
			* sizeof(char))) == NULL)
			return (NULL);
		count = 0;
		while (s[count] != '\0')
		{
			str[count] = (*f)(count, s[count]);
			++count;
		}
		str[ft_strlen((char *)(uintptr_t)s)] = '\0';
		return (str);
	}
	return (NULL);
}
