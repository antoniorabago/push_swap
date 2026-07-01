/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_alg_adapt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 15:54:32 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/18 15:54:34 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_alg_adapt(t_stack *sta, t_stack *stb, int *op_count, t_parse *param)
{
	if (sta->size <= 5)
	{
		param->algoritm = 1;
		ps_alg_small(sta, stb, op_count);
	}
	if (sta->size <= 15 || param->disorder < 0.10)
	{
		param->algoritm = 1;
		ps_alg_simple(sta, stb, op_count);
	}
	else if (sta->size <= 350)
	{
		param->algoritm = 2;
		ps_alg_medium(sta, stb, op_count);
	}
	else
	{
		param->algoritm = 3;
		ps_alg_complex(sta, stb, op_count);
	}
}
