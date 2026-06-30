/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:07:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 17:07:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *st)
{
	t_node	*second;

	second = (st->start)->next;
	(st->start)->next = second->next;
	second->next = st->start;
	st->start = second;
}

void	sa(t_stack *sta, int *op_count)
{
	ft_printf("sa\n");
	swap(sta);
	op_count[0]++;
}

void	sb(t_stack *stb, int *op_count)
{
	ft_printf("sb\n");
	swap(stb);
	op_count[1]++;
}

void	ss(t_stack *sta, t_stack *stb, int *op_count)
{
	ft_printf("ss\n");
	swap(sta);
	swap(stb);
	op_count[2]++;
}
