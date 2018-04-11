/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 16:26:48 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:50 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lst_size(t_list *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}
