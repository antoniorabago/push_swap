/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:07:58 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 17:08:01 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *st)
{
	t_node	*last;
	t_node	*temp;

	if (!st || !st->start || !st->start->next)
		return ;
	last = ft_lstlast(st->start);
	temp = st->start;
	st->start = (st->start)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_stack *sta, int *op_count)
{
	ft_printf("ra\n");
	rotate(sta);
	op_count[5]++;
}

void	rb(t_stack *stb, int *op_count)
{
	ft_printf("rb\n");
	rotate(stb);
	op_count[6]++;
}

void	rr(t_stack *sta, t_stack *stb, int *op_count)
{
	ft_printf("rr\n");
	rotate(sta);
	rotate(stb);
	op_count[7]++;
}
