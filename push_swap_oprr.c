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

static void	revrotate(t_node **first)
{
	t_node	*last;
	t_node	*second2last;

	second2last = ft_lst_secondtolast(*first);
	last = second2last->next;
	second2last->next = NULL;
	last->next = *first;
	*first = last;
}

void	rra(t_node **a)
{
	ft_printf("rra\n");
	revrotate(a);
}

void	rrb(t_node **b)
{
	ft_printf("rrb\n");
	revrotate(b);
}

void	rrr(t_node **a, t_node **b)
{
	ft_printf("rrr\n");
	revrotate(a);
	revrotate(b);
}

