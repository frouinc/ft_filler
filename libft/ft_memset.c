/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:58:08 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:58 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	if (b == NULL)
		return (NULL);
	tmp = b;
	if (len == 0)
		return (b);
	while (--len >= 1)
		tmp[len] = (unsigned char)c;
	tmp[0] = (unsigned char)c;
	return (tmp);
}
