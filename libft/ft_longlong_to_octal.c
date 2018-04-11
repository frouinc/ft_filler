/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlong_to_octal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 19:47:50 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:48 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*decal(char *octal)
{
	int			count;

	while (octal[0] == 'a')
	{
		count = -1;
		while (octal[++count + 1] != '\0')
			octal[count] = octal[count + 1];
		octal[count] = '\0';
	}
	return (octal);
}

char			*ft_longlong_to_octal(unsigned long long nbr)
{
	char		*octal;
	int			len;

	len = ft_longlonglen_unsigned(nbr) + 4;
	if ((octal = malloc((size_t)len * sizeof(char))) == NULL)
		return (NULL);
	octal[len - 1] = '\0';
	len = len - 2;
	if (nbr == 0)
		octal[len--] = '0';
	else
		while (nbr > 0)
		{
			octal[len] = (nbr % 8) + 48;
			nbr /= 8;
			--len;
		}
	while (len >= 0)
	{
		octal[len] = 'a';
		--len;
	}
	return (decal(octal));
}
