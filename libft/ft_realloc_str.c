/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:20:21 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:52:17 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc_str(char *ptr, size_t size)
{
	char	*str;

	if (ptr == NULL)
		return (malloc(size));
	if ((str = ft_strnew((ft_strlen(ptr) + size + 1) * sizeof(char))) == NULL)
		return (NULL);
	str = ft_strncpy(str, ptr, ft_strlen(ptr));
	free(ptr);
	return (str);
}
