/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg_complex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_alg_complex_cols(t_stack *sta, t_stack *stb, int *op_count, int i)
{
	int	j;
	int	size;

	j = 0;
	size = sta->size;
	while (j < size)
	{
		if (((sta->start->index >> i) & 1) == 1)
			ra(sta, op_count);
		else
			pb(sta, stb, op_count);
		j++;
	}
}

void	ps_alg_complex(t_stack *sta, t_stack *stb, int *op_count)
{
	int	i;
	int	size;
	int	max_bits;

	size = sta->size;
	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		if (ps_stack_disorder(sta) != 0)
			ps_alg_complex_cols(sta, stb, op_count, i);
		while (stb->size)
			pa(sta, stb, op_count);
		i++;
	}
}
