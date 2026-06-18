/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_opp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:07:48 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 17:07:49 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **origin, t_node **destiny)
{
	t_node	*moving;
	t_node	*second;

	if(*origin)
	{
		moving = *origin;
		second = (*origin)->next;
		moving->next = *destiny;
		*origin = second;
		*destiny = moving;
	}
}

void	pa(t_node **a, t_node **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_node **a, t_node **b)
{
	ft_printf("pb\n");
	push(a, b);
}
