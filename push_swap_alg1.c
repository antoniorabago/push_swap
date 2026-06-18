/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg1.c                                   :+:      :+:    :+:   */
/*   By: arabago- <arabago-@student.42madrid.com>     +:+ +:+         +:+     */
/*       seoliver <seoliver@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_alg1_get_min(t_node *lst)
{
	int		min;
	
	if(!lst)
		return (0);
	if (lst->num && ! lst->next)
		return (lst->num);
	if (lst->num < lst->next->num)
		min = lst->num;
	else
		min = lst->next->num;
	lst = lst->next;
	while (lst)
	{
		if(lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	return (min);
}

static void ps_alg1_pb_min(int min, t_node **a, t_node **b)
{
	t_node	*lst;
	
	lst = *a;
	while (lst)
	{
		if(min == lst->num)
		{
			pb(a, b);
			return ;
		}
		lst = lst->next;
		ra(a, b);
	}
}

static void ps_alg1_pa_everything(t_node **a, t_node **b)
{
	t_node	*lst;
	
	lst = *b;
	while (lst)
	{
		pa(a, b);
		lst = *b;
	}
}

void ps_alg1(t_node **a, t_node **b)
{
	int		i;
	int		min;
	int		size;
	t_node	*lst;
	
	i = 0;
	lst = *a;
	while (lst)
	{
		min = ps_alg1_get_min(*a);
		ps_alg1_pb_min(min, a, b);
		lst = *a;
	}
	ps_alg1_pa_everything(a, b);
}
