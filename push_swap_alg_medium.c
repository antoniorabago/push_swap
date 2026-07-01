/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg_medium.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
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
	while (i < pos)
	{
		op(stb, op_count);
		i++;
	}
	pa(sta, stb, op_count);
	return ;
}

int	ps_medium_get_max_pos(t_stack *stb)
{
	long	max;
	int		max_pos;
	t_node	*lst;
	int		i;

	i = 0;
	lst = stb->start;
	if (!lst)
		return (-1);
	max = lst->num;
	max_pos = 0;
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

void	ps_med_chunk(t_stack *sta, t_stack *stb, int *op_count, t_limit limit)
{
	int	i;
	int	len;

	i = 0;
	len = sta->size;
	while (i < len)
	{
		if (sta->start->index <= limit.max)
		{
			pb(sta, stb, op_count);
			if (stb->start->index <= limit.rotate_limit)
			{
				if (sta->start && sta->start->index > limit.max)
				{
					rr(sta, stb, op_count);
					i++;
				}
				else
					rb(stb, op_count);
			}
		}
		else
			ra(sta, op_count);
		i++;
	}
}

void	ps_alg_medium(t_stack *sta, t_stack *stb, int *op_count)
{
	int		third;
	int		len;
	int		i;
	t_limit	limit;

	if (ps_stack_disorder(sta) == 0)
		return ;
	third = sta->size / 3;
	limit = (t_limit){third, third / 2};
	ps_med_chunk(sta, stb, op_count, limit);
	limit = (t_limit){third * 2, third + third / 2};
	ps_med_chunk(sta, stb, op_count, limit);
	limit = (t_limit){third * 4, third * 2 + third / 2};
	ps_med_chunk(sta, stb, op_count, limit);
	i = 0;
	len = stb->size;
	while (i < len)
	{
		if (stb->size == 1)
			pa(sta, stb, op_count);
		else
			ps_medium_find_pa(ps_medium_get_max_pos(stb), sta, stb, op_count);
		i++;
	}
}
