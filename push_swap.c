/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*   By: arabago- <arabago-@student.42madrid.com>     +:+ +:+         +:+     */
/*       seoliver <seoliver@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:47:24 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 17:47:26 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double ps_stack_disorder(t_stack *st)
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


static void ps_exec_alg(t_parse *param, t_stack *sta, t_stack *stb, int *op_count)
{
	param->disorder = ps_stack_disorder(sta);
	if (param->algoritm == 1 || (param->algoritm == 0 && param->disorder < 0.2))
	{
		//printf("--Simple\n\n");
		ps_alg_simple(sta, stb, op_count);
	}
	else if (param->algoritm == 2 || (param->algoritm == 0 && (param->disorder >= 0.2 && param->disorder < 0.5)))
	{
		//printf("--Medium\n\n");
		ps_alg_medium(sta, stb, op_count);
	}
	else
	{
		//printf("--Complex\n\n");
		param->algoritm = 3;	
	}
}

static void ps_print_operations(int total_ops, int * opc)
{
	ft_printf("[bench] total_ops: %d \n", total_ops);
	ft_printf("[bench] sa: %d sb: %d ss: %d ", opc[0], opc[1], opc[2]);
	ft_printf("pa: %d pb: %d \n", opc[3], opc[4]);
	ft_printf("[bench] ra: %d rb: %d rr: %d ", opc[5], opc[6], opc[7]);
	ft_printf("rra: %d rrb: %d rrr: %d\n", opc[8], opc[9], opc [10]);
}

static void ps_print_bench(t_parse param, int *opc)
{
	int i;
	int total_ops;

	i = 0;
	total_ops = 0;
	while (i < 11)
	{
		total_ops += opc[i];
		i++;
	}
	// Se usa printf porque en ft_printf no existe %f
	printf("[bench] disorder: %.2f%%\n", param.disorder * 100);
	if (param.algoritm == 1)
		ft_printf("[bench] strategy: Simple / O(n2))\n");	
	else if (param.algoritm == 2)
		ft_printf("[bench] strategy: Medium / O(n√n)\n");
	else if (param.algoritm == 3)
		ft_printf("[bench] strategy: Complex / O(n log n)\n");
	else if (param.algoritm == 0 && param.disorder < 0.2)
		ft_printf("[bench] strategy: Adaptive / O(n2)\n");
	else if (param.algoritm == 0 && (param.disorder >= 0.2 && param.disorder < 0.5))
		ft_printf("[bench] strategy: Adaptive / O(n√n)\n");
	else 
		ft_printf("[bench] strategy: Adaptive / O(n log n)\n");
	ps_print_operations(total_ops, opc);
}

int main(int argc, char **argv)
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

	ps_get_index(&stack_a);
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

	ps_exec_alg(&param, &stack_a, &stack_b, op_count);
	
	// ft_printf("\npila a: ");
	// ft_print_nums(stack_a.start);
	// ft_printf("\n");
	// ft_printf("pila b: ");
	// ft_print_nums(stack_b.start);
	// ft_printf("\n");

	if (param.bench == 1)
		ps_print_bench(param, op_count);

	ft_lstclear(&stack_a.start);
	ft_lstclear(&stack_b.start);
	//ft_printf("\n END \n");
	return (0);
}
