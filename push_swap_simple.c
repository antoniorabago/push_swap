/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_simple.c                                 :+:      :+:    :+:   */
/*   By: arabago- <arabago-@student.42madrid.com>     +:+ +:+         +:+     */
/*       seoliver <seoliver@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_simple_get_min(t_stack *sta)
{
	int		min;
	t_node	*lst;

	lst = sta->start;
	if (!lst)
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
		if (lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	return (min);
}

static int	ps_simple_pb_min(int min, t_stack *sta, t_stack *stb, int *op_count)
{
	int	i;

	i = 0;
	while (i < sta->size)
	{
		if (min == sta->start->num)
		{
			pb(sta, stb, op_count);
			return (1);
		}
		ra(sta, op_count);
		i++;
	}
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
			min = ps_simple_get_min(sta);
			ps_simple_pb_min(min, sta, stb, op_count);
		}
		else
			break ;
	}
	ps_simple_pa_all(sta, stb, op_count);
}
