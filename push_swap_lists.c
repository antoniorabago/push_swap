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

int	ft_lstsize(t_node *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

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

void ft_get_index(t_node *lst)
{
    int index;
    t_node *next;
    t_node *ptr_minor;
    t_node *original;

    index = 1;
	original = lst;
	ft_printf("ft_get_index\n");
    //Recorremos la lista hasta el final de la lista
    while (lst)
    {
		ptr_minor = lst;
		next = lst->next;
		while (next && next->next != NULL)
		{
			//Mientras que no lleguemos al final de la lista
			//Recorremos la lista hasta que haya un elemento sin index 0
			if (next->index == 0)
			{
				//Si encontramos un número menor dejamos el ptr_minor apuntando a ese nodo
				ft_printf("compare: lst %d > next %d \n", lst->num, next->num);
				if (ptr_minor->num > next->num)
				{
					ptr_minor = next;
				}
			}
			next = next->next;
		}
		// Asignamos el index
		ft_printf("assign index %d to number %d \n", index, ptr_minor->num);
		ptr_minor->index = index;
		index++;
		ft_print_nbrs(original);
		lst = lst->next;
	}
}
