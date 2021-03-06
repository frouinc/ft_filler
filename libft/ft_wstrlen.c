/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:55:19 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:38 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrlen(wchar_t *s)
{
	char		*bin;
	int			count;
	int			size;

	if (s == NULL)
		return (0);
	size = 0;
	count = -1;
	while (s[++count] != '\0')
	{
		if ((bin = ft_longlong_to_binaire((unsigned long long)s[count]))
			== NULL)
			return (-1);
		size += ((int)ft_strlen(bin) / 8) + 1;
		if (((int)ft_strlen(bin) % 8) != 0)
			++size;
		free(bin);
	}
	return (size);
}
