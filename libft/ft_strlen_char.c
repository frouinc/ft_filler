/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:11:27 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:22 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_char(char *str, char c)
{
	size_t	count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != c && str[count] != '\0')
		++count;
	return (count);
}
