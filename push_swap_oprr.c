/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_oprr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:08:07 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 17:08:09 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	revrotate(t_stack *st)
{
	t_node	*last;
	t_node	*second2last;

	if (!st || !st->start || !st->start->next)
		return ;
	second2last = ft_lst_secondtolast(st->start);
	last = second2last->next;
	second2last->next = NULL;
	last->next = st->start;
	st->start = last;
}

void	rra(t_stack *sta, int *op_count)
{
	ft_printf("rra\n");
	revrotate(sta);
	op_count[8]++;
}

void	rrb(t_stack *stb, int *op_count)
{
	ft_printf("rrb\n");
	revrotate(stb);
	op_count[9]++;
}

void	rrr(t_stack *sta, t_stack *stb, int *op_count)
{
	ft_printf("rrr\n");
	revrotate(sta);
	revrotate(stb);
	op_count[10]++;
}
