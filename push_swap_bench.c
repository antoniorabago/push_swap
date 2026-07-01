/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.com>   +#+  +:+       +#+        */
/*       seoliver <seoliver@student.42madrid.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:47:24 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 17:47:26 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_bench_disorder(t_parse param)
{
	ft_printf_fd(2, "[bench] disorder: %d.", (int)(param.disorder * 100));
	ft_printf_fd(2, "%d", (int)((param.disorder * 10000 + 0.5)) % 100);
	if ((int)((param.disorder * 10000 + 0.5)) % 10 == 0)
		ft_printf_fd(2, "0");
	ft_printf_fd(2, "%%\n", (int)((param.disorder * 10000 + 0.5)) % 100);
}

static void	ps_bench_algoritm(t_parse param, t_stack *sta)
{
	if (param.algoritm == 1)
		ft_printf_fd(2, "[bench] strategy: Simple / O(n2))\n");
	else if (param.algoritm == 2)
		ft_printf_fd(2, "[bench] strategy: Medium / O(n√n)\n");
	else if (param.algoritm == 3)
		ft_printf_fd(2, "[bench] strategy: Complex / O(n log n)\n");
	else if (param.algoritm == 0 && (sta->size <= 5 || param.disorder < 0.2))
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n2)\n");
	else if (param.algoritm == 0
		&& (param.disorder >= 0.2 && param.disorder < 0.5))
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n√n)\n");
	else
		ft_printf_fd(2, "[bench] strategy: Adaptive / O(n log n)\n");
}

static void	ps_bench_operations(int total_ops, int *opc)
{
	ft_printf_fd(2, "[bench] total_ops: %d \n", total_ops);
	ft_printf_fd(2, "[bench] sa: %d sb: %d ss: %d ", opc[0], opc[1], opc[2]);
	ft_printf_fd(2, "pa: %d pb: %d \n", opc[3], opc[4]);
	ft_printf_fd(2, "[bench] ra: %d rb: %d rr: %d ", opc[5], opc[6], opc[7]);
	ft_printf_fd(2, "rra: %d rrb: %d rrr: %d\n", opc[8], opc[9], opc [10]);
}

void	ps_bench(t_parse param, t_stack *sta, int *opc)
{
	int		i;
	int		total_ops;

	i = 0;
	total_ops = 0;
	while (i < 11)
	{
		total_ops += opc[i];
		i++;
	}
	ps_bench_disorder(param);
	ps_bench_algoritm(param, sta);
	ps_bench_operations(total_ops, opc);
}
