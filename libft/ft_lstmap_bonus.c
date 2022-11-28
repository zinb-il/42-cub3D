/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ziloughm <ziloughm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:25:57 by omeslall          #+#    #+#             */
/*   Updated: 2022/11/28 22:28:34 by ziloughm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**index;
	t_list	*new;
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	index = &new;
	while (temp)
	{
		new = ft_lstnew((f)(temp->content));
		if (!new)
		{
			ft_lstclear(index, del);
			return (NULL);
		}
		temp = temp->next;
		ft_lstadd_back(index, new);
	}
	return (new);
}
