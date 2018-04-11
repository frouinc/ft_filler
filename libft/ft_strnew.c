/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:09:47 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:28 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if ((str = malloc((size + 1) * sizeof(char))) == NULL)
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}
