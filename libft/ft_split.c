/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 18:59:03 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:42:12 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char *str, int count, int word, int size)
{
	char		**tab;
	int			count2;

	if ((tab = malloc((ft_strlen_words(str, ' ') + 1) * sizeof(char *)))
		== NULL)
		return (NULL);
	while (count < size)
	{
		while (str[count] == ' ')
			++count;
		if (str[count] != '\0')
		{
			count2 = count;
			while (str[count2] != ' ' && str[count2] != '\0')
				++count2;
			if ((tab[++word] = ft_strnew(count2)) == NULL)
				return (NULL);
			count2 = -1;
			--count;
			while (str[++count] != ' ' && str[count] != '\0')
				tab[word][++count2] = str[count];
		}
	}
	tab[word + 1] = NULL;
	return (tab);
}
