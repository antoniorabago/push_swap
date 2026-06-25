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

	last = ft_lstlast(st->start);
	temp = st->start;
	st->start = (st->start)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_stack *sta)
{
	ft_printf("ra\n");
	rotate(sta);
}

void	rb(t_stack *stb)
{
	ft_printf("rb\n");
	rotate(stb);
}

void	rr(t_stack *sta, t_stack *stb)
{
	ft_printf("rr\n");
	rotate(sta);
	rotate(stb);
}
