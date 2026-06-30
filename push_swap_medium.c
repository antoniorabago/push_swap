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

void	ps_medium_find_pa(int pos, t_stack *sta, t_stack *stb, int *op_count)
{
	int		i;
	void	(*op)(t_stack *, int *op_count);

	i = 0;
	if (pos < stb->size / 2)
		op = rb;
	else
	{
		op = rrb;
		pos = stb->size - pos;
	}
	while (i < stb->size)
	{
		if (pos == i)
		{
			pa(sta, stb, op_count);
			break ;
		}
		op(stb, op_count);
		i++;
	}
	return ;
}

int	ps_medium_get_max_pos(t_stack *stb)
{
	int		max;
	int		max_pos;
	t_node	*lst;
	int		i;

	i = 0;
	lst = stb->start;
	if (!lst)
		return (-1);
	if (lst->num && ! lst->next)
		return (i);
	if (lst->num > lst->next->num)
		max = lst->num;
	else
	{
		max = lst->next->num;
		lst = lst->next;
		i++;
	}
	max_pos = i;
	lst = lst->next;
	i++;
	while (lst)
	{
		if (lst->num > max)
		{
			max = lst->num;
			max_pos = i;
		}
		lst = lst->next;
		i++;
	}
	return (max_pos);
}

void	ps_med_chunk(t_stack *sta, t_stack *stb, int *op_count, int c1, int c2)
{
	int	i;
	int	len;

	i = 0;
	len = sta->size;
	if (ps_stack_disorder(sta) != 0 || sta->size == 1)
	{
		while (i < len)
		{
			if (sta->start->index <= c1)
			{
				if (sta->start->index <= c2)
				{
					pb(sta, stb, op_count);
					rb(stb, op_count);
				}
				else
					pb(sta, stb, op_count);
			}
			else
				ra(sta, op_count);
			i++;
		}
	}
}

void	ps_alg_medium(t_stack *sta, t_stack *stb, int *op_count)
{
	int	third;
	int	max_pos;
	int	len;
	int	i;

	third = sta->size / 3;
	ps_med_chunk(sta, stb, op_count, third, third / 2);
	ps_med_chunk(sta, stb, op_count, third * 2, third + third / 2);
	ps_med_chunk(sta, stb, op_count, third * 4, third * 2 + third / 2);
	ps_medium_find_pa(ps_medium_get_max_pos(stb), sta, stb, op_count);
	ps_medium_find_pa(ps_medium_get_max_pos(stb), sta, stb, op_count);
	// TODO: si max esta a dos posiciones, pa; si no, pa del top b si > bottom a
	i = 0;
	len = stb->size;
	while (i < len)
	{
		if (stb->size == 1)
			pa(sta, stb, op_count);
		else
		{
			max_pos = ps_medium_get_max_pos(stb);
			ps_medium_find_pa(max_pos, sta, stb, op_count);
		}
		i++;
	}
}
