/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrouin <cfrouin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 13:07:45 by cfrouin           #+#    #+#             */
/*   Updated: 2017/10/25 15:41:52 by cfrouin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*first;
	t_list	*tmp2;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	tmp2 = f(lst);
	if ((first = ft_lstnew(tmp2->content, tmp2->content_size)) == NULL)
		return (NULL);
	tmp = first;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp2 = f(lst);
		if ((tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)) == NULL)
			return (NULL);
		tmp2 = tmp2->next;
		tmp = tmp->next;
		lst = lst->next;
	}
	return (first);
}
