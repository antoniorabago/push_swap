/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.com>   +#+  +:+       +#+        */
/*       seoliver <seoliver@student.42madrid.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:47:24 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 17:47:26 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	ps_stack_disorder(t_stack *st)
{
	int		mistakes;
	int		total_pairs;
	t_node	*i;
	t_node	*j;

	mistakes = 0;
	total_pairs = 0;
	i = st->start;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->num > j->num)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return ((double)mistakes / total_pairs);
}

static void	ps_exec_alg(t_parse *param, t_stack *sta, t_stack *stb, int *opc)
{
	param->disorder = ps_stack_disorder(sta);
	if (sta->size <= 5)
		ps_alg_small(sta, stb, opc);
	else if (param->algoritm == 1
		|| (param->algoritm == 0 && param->disorder < 0.2))
		ps_alg_simple(sta, stb, opc);
	else if (param->algoritm == 2
		|| (param->algoritm == 0
			&& (param->disorder >= 0.2 && param->disorder < 0.5)))
		ps_alg_medium(sta, stb, opc);
	else
		ps_alg_complex(sta, stb, opc);
}

int	main(int argc, char **argv)
{
	int		i;
	int		op_count[11];
	t_stack	stack_a;
	t_stack	stack_b;
	t_parse	param;

	if (ps_parsing(argv, &stack_a, &stack_b, &param))
	{
		ft_lstclear(&stack_a.start);
		ft_lstclear(&stack_b.start);
		return (1);
	}
	ps_set_index(&stack_a);
	//ft_printf("\nSe han cargado %d números \n", stack_a.size);
	i = 0;
	while (i < 11)
	{
		op_count[i] = 0;
		i++;
	}
	// ft_printf("\npila a: ");
	// ft_print_nums(stack_a.start);
	// ft_printf("\n\n");
	if (ps_stack_disorder(&stack_a) != 0)
		ps_exec_alg(&param, &stack_a, &stack_b, op_count);
	// ft_printf("\npila a: ");
	// ft_print_nums(stack_a.start);
	// ft_printf("\n");
	// ft_printf("pila b: ");
	// ft_print_nums(stack_b.start);
	// ft_printf("\n");
	if (param.bench == 1)
		ps_bench(param, &stack_a, op_count);
	ft_lstclear(&stack_a.start);
	ft_lstclear(&stack_b.start);
	//ft_printf("\n END \n");
	return (0);
}
