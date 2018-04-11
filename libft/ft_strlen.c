/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:22:35 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:23 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(char *str)
{
	size_t		count;

	if (str == NULL)
		return (0);
	count = 0;
	while (str[count] != '\0')
		++count;
	return (count);
}
