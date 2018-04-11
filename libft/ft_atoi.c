/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:17:31 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:08:16 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		resultat;
	int		count;
	int		flag;

	if (str == NULL)
		return (-1);
	resultat = 0;
	count = 0;
	flag = 1;
	while (str[count] == '\f' || str[count] == '\n' || str[count] == '\r'
		|| str[count] == '\t' || str[count] == '\v' || str[count] == ' ')
		++count;
	if (str[count] == '-' || str[count] == '+')
		if (str[count++] == '-')
			flag = -1;
	while (str[count] != '\0')
	{
		if (str[count] < '0' || str[count] > '9')
			return (resultat * flag);
		resultat = (resultat * 10) + (str[count] - '0');
		++count;
	}
	return (resultat * flag);
}
