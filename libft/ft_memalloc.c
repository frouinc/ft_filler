/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:34:06 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:53 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*ptr;

	if ((ptr = malloc(size)) == NULL)
		return (NULL);
	ptr = ft_memset(ptr, 0, size);
	return (ptr);
}
