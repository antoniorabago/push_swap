/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lists.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:53:33 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 17:53:35 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int num)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->num = num;
	list->index = 0;
	list->next = NULL;
	return (list);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		last = lst;
		lst = lst->next;
	}
	return (last);
}

t_node	*ft_lst_secondtolast(t_node *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_lstclear(t_node **lst)
{
	t_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}
