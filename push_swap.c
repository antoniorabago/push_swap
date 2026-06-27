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

static double ps_stack_disorder(t_stack *st)
{
    int     mistakes;
    int     total_pairs;
    t_node  *i;
    t_node  *j;

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

int	main(int argc, char **argv)
{
	//int i;
	//int bench;
	int pa_count;
	int pb_count;
	int ra_count;
	t_stack stack_a;
	t_stack stack_b;
	t_parse param;

	//Parsing
	if (ps_parsing(argc, argv, &stack_a, &stack_b, &param))
		return (1);

	//Si el algoritmo es adaptive se selecciona el algoritmo a usar
	if (param.algoritm == 0)
		param.disorder = ps_stack_disorder(&stack_a);
	
	//Cargar index 
	ft_printf("\n\n== ft_get_index ==\n");
	ps_get_index(&stack_a);
	ft_print_nbrs(stack_a.start);
	ft_print_nbrs(stack_b.start);

	//Algoritmo simple
	pa_count = 0;
	pb_count = 0;
	ra_count = 0;
	ft_printf("\n\n== simple ==\n");
	ft_printf("pila a: \n"); ft_print_nums(stack_a.start); ft_printf("\n");
	ps_alg_simple(&stack_a, &stack_b, &pa_count, &pb_count, &ra_count);
	ft_printf("pila a: "); ft_print_nums(stack_a.start); ft_printf("\n");
	ft_printf("pila b: "); ft_print_nums(stack_b.start); ft_printf("\n");
	
	//Modo benchmark
	if (param.bench == 1)
	{
		ft_printf("\nBench \n");
		//Se usa printf porque en ft_printf no existe %f
		printf("[bench] disorder: %.2f%%\n", param.disorder * 100);
		ft_printf("[bench] total_ops: %d \n", pa_count + pb_count + ra_count);
		ft_printf("[bench] pa: %d \n", pa_count);
		ft_printf("[bench] pb: %d \n", pb_count);
		ft_printf("[bench] ra: %d \n", ra_count);
	}

	//Liberamos la memoria de las pilas
	ft_lstclear(&stack_a.start);
	ft_lstclear(&stack_b.start);

	ft_printf("\n END \n");

	return (0);
}
