/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_words.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:06:40 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlen_words(char *str, char c)
{
	size_t		count;
	size_t		nb;
	size_t		size;

	count = 0;
	nb = 0;
	size = (int)ft_strlen(str);
	while (count < size)
	{
		while (str[count] == c)
			++count;
		if (str[count] != '\0')
			++nb;
		while (str[count] != '\0' && str[count] != c)
			++count;
	}
	return (nb);
}
