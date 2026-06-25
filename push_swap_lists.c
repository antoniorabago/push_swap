/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_nodes.c                                  :+:      :+:    :+:   */
/*   By: arabago- <arabago-@student.42madrid.com>     +:+ +:+         +:+     */
/*       seoliver <seoliver@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:53:33 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 17:53:35 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_lstsize(t_node *lst)
// {
// 	int	i;

// 	i = 0;
// 	while (lst != NULL)
// 	{
// 		i++;
// 		lst = lst->next;
// 	}
// 	return (i);
// }

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
	t_node	*last;
	t_node	*sec2last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (last)
			sec2last = last;
		last = lst;
		lst = lst->next;
	}
	return (sec2last);
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


void	ft_print_nbrs(t_node *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("Num: %i index: %i\n", lst->num, lst->index);
		lst = lst->next;
	}
}

void	ft_print_nums(t_node *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("%i ", lst->num);
		lst = lst->next;
	}
}

static t_node *ps_get_min(t_node *lst)
{
	t_node		*min;

	//Saltar todos los index con valor
	while (lst->index != 0)
	{
		lst = lst->next;
	}
	min = lst;
	//Recorrer lista buscando el min sin index
	while(lst->next)
	{
		if(lst->next->num < min->num && lst->next->index == 0)
			min = lst->next;
		lst = lst->next;
	}
	return (min);
}


void ps_get_index(t_stack *st)
{
	int i;
	int index;
    t_node *min;

	i = 0;
    index = 1;
	min = NULL;

    //Recorrer toda la lista 
    while (i < st->size)
    {
		//Buscar minimo sin index
		min = ps_get_min(st->start);
		min->index = index;
		i++;
        index++;
    }
}