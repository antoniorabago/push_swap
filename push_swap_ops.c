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

static void	swap(t_node **first)
{
	t_node	*second;

	second = (*first)->next;
	(*first)->next = second->next;
	second->next = *first;
	*first = second;
}

void	sa(t_node **a)
{
	ft_printf("sa\n");
	swap(a);
}

void	sb(t_node **b)
{
	ft_printf("sb\n");
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	ft_printf("ss\n");
	swap(a);
	swap(b);
}
