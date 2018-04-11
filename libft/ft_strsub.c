/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:15:44 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:33 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	if (s != NULL)
	{
		if ((str = malloc((len + 1) * sizeof(char))) == NULL)
			return (NULL);
		count = 0;
		while (count < len)
		{
			str[count] = s[count + start];
			++count;
		}
		str[count] = '\0';
		return (str);
	}
	return (NULL);
}
