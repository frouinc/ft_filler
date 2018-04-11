/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:33:35 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:32 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		count;
	int		count2;
	int		size_little;
	int		tmp;

	if (str == NULL || to_find == NULL)
		return (NULL);
	size_little = (int)ft_strlen((char *)(uintptr_t)to_find);
	if (size_little == 0)
		return ((char *)(uintptr_t)str);
	count = -1;
	while (str[++count] != '\0')
	{
		count2 = -1;
		tmp = count;
		while (str[count] == to_find[++count2] && str[count])
			++count;
		if (count2 == size_little)
			return ((char *)(uintptr_t)&str[count - size_little]);
		count = tmp;
	}
	return (NULL);
}
