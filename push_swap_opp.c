/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:07:48 by seoliver          #+#    #+#             */
/*   Updated: 2026/07/01 15:33:31 by arabago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *storigin, t_stack *stdestiny)
{
	t_node	*moving;
	t_node	*second;

	if (storigin)
	{
		moving = storigin->start;
		second = storigin->start->next;
		moving->next = stdestiny->start;
		storigin->start = second;
		stdestiny->start = moving;
		storigin->size--;
		stdestiny->size++;
	}
}

void	pa(t_stack *sta, t_stack *stb, int *op_count)
{
	ft_printf("pa\n");
	push(stb, sta);
	op_count[3]++;
}

void	pb(t_stack *sta, t_stack *stb, int *op_count)
{
	ft_printf("pb\n");
	push(sta, stb);
	op_count[4]++;
}
