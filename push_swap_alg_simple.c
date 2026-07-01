/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg_simple.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_simple_get_min_pos(t_stack *sta)
{
	int		min;
	int		min_pos;
	t_node	*lst;
	int		i;

	i = 0;
	lst = sta->start;
	if (!lst)
		return (-1);
	min = lst->num;
	min_pos = 0;
	while (lst)
	{
		if (lst->num < min)
		{
			min = lst->num;
			min_pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (min_pos);
}

static int	ps_simple_pb_min(int pos, t_stack *sta, t_stack *stb, int *op_count)
{
	int		i;
	void	(*op)(t_stack *, int *op_count);

	i = 0;
	if (pos < sta->size / 2)
		op = ra;
	else
	{
		op = rra;
		pos = sta->size - pos;
	}
	while (i < pos)
	{
		op(sta, op_count);
		i++;
	}
	pb(sta, stb, op_count);
	return (0);
}

static void	ps_simple_pa_all(t_stack *sta, t_stack *stb, int *op_count)
{
	while (stb->size > 0)
		pa(sta, stb, op_count);
}

void	ps_alg_simple(t_stack *sta, t_stack *stb, int *op_count)
{
	int		min;

	while (sta->size > 0)
	{
		if (ps_stack_disorder(sta) != 0)
		{
			min = ps_simple_get_min_pos(sta);
			ps_simple_pb_min(min, sta, stb, op_count);
		}
		else
			break ;
	}
	ps_simple_pa_all(sta, stb, op_count);
}
