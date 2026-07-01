/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg_small.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_find_index_pos(t_stack *sta, int index)
{
	int		pos;
	t_node	*lst;

	pos = 0;
	lst = sta->start;
	while (lst)
	{
		if (lst->index == index)
			return (pos);
		pos++;
		lst = lst->next;
	}
	return (-1);
}

static void	ps_push_i(t_stack *sta, t_stack *stb, int *op_count, int index)
{
	int	pos;

	pos = ps_find_index_pos(sta, index);
	if (pos <= sta->size / 2)
	{
		while (pos-- > 0)
			ra(sta, op_count);
	}
	else
	{
		pos = sta->size - pos;
		while (pos-- > 0)
			rra(sta, op_count);
	}
	pb(sta, stb, op_count);
}

static void	ps_sort_three(t_stack *sta, int *op_count)
{
	int	a;
	int	b;
	int	c;

	a = sta->start->index;
	b = sta->start->next->index;
	c = sta->start->next->next->index;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(sta, op_count);
	else if (a > b && b > c)
	{
		sa(sta, op_count);
		rra(sta, op_count);
	}
	else if (a > b && b < c && a > c)
		ra(sta, op_count);
	else if (a < b && b > c && a < c)
	{
		sa(sta, op_count);
		ra(sta, op_count);
	}
	else
		rra(sta, op_count);
}

static void	ps_sort_five(t_stack *sta, t_stack *stb, int *op_count)
{
	int	size;

	size = sta->size;
	if (size == 5)
		ps_push_i(sta, stb, op_count, 1);
	ps_push_i(sta, stb, op_count, 2);
	ps_sort_three(sta, op_count);
	pa(sta, stb, op_count);
	if (size == 5)
		pa(sta, stb, op_count);
}

void	ps_alg_small(t_stack *sta, t_stack *stb, int *op_count)
{
	if (sta->size == 2)
	{
		if (sta->start->index > sta->start->next->index)
			sa(sta, op_count);
	}
	else if (sta->size == 3)
		ps_sort_three(sta, op_count);
	else
		ps_sort_five(sta, stb, op_count);
}
