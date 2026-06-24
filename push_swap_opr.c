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

static void	rotate(t_node **first)
{
	t_node	*last;
	t_node	*temp;

	last = ft_lstlast(*first);
	temp = *first;
	*first = (*first)->next;
	temp->next = NULL;
	last->next = temp;
}

void	ra(t_node **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_node **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}
