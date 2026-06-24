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

double stack_disorder(t_node *lst)
{
    int     mistakes;
    int     total_pairs;
    t_node  *i;
    t_node  *j;

    mistakes = 0;
    total_pairs = 0;

    i = lst;
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

void ps_select_alg(char *argv)
{
	if (strcmp(argv, "--simple") == 0)
		ft_printf("Simple \n");
	else if (strcmp(argv, "--medium") == 0)
		ft_printf("Medium \n");
	else if (strcmp(argv, "--complex") == 0)
		ft_printf("Complex \n");
	else
		ft_printf("Adaptative \n");
}

int	ps_valid_number(char *argv, t_node *lst)
{
	int	i;

	i = 0;
	if(argv[i] == '-')
		i++;
	while (argv[i])
	{
		if(argv[i] < '0' && argv[i] > '9')
			return (0);
		i++;
	}
	// check not duplicate
	while (lst)
	{
		if(lst->num == ft_atoi(argv))
			return (0);
		lst = lst->next;
	}
	// TODO: check not integer
	return (1);
}

int ps_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

void ft_stack_init(t_stack *st)
{
	st->start = NULL;
	st->end = NULL;
	st->size = 0;
}

int	main(int argc, char **argv)
{
	int	i;
	t_node	*a;
	t_node	*b;
	t_stack stack_a;
	t_stack stack_b;

	// parsing:
	if (argc < 3)
	{
		ft_putstr("Error: Provide at least 2 numbers as args.");
		return (1);
	}
	i = 1;
	if (strcmp(argv[i], "--bench") == 0)
	{
		ft_printf("Bench \n");
		i++;
	}

	// TODO: add adaptative by default

	//Seleccionar algoritmo
	if (argv[i][0] == '-' && argv[i][1] == '-')
	{
		ps_select_alg(argv[i]);
		i++;
	}

	//Validar números (sin duplicados)
	if(!ps_valid_number(argv[i], NULL))
		return (ps_error());

	//Inicializar lista y pilas
	a = NULL;
	ft_stack_init(&stack_a);
	ft_stack_init(&stack_b);

	//Cargar datos lista y pila
	while (i < argc)
	{
		if(!ps_valid_number(argv[i], a))
			return (ps_error());

		ft_lstadd_back(&a, ft_lstnew(ft_atoi(argv[i])));
		i++;
		stack_a.size++;
	}
	stack_a.start = a;
	stack_a.end = ft_lstlast(a);
	printf("El primer elemento de la pila a es: %d \n", stack_a.start->num);
	printf("El último elemento de la pila a es: %d \n", stack_a.end->num);
	printf("El tamaño de la pila a es: %d \n", stack_a.size);

	//Indice de Desorden
	printf("Disorder index: %f \n", stack_disorder(a));
	
	//Cargar index 
	ft_printf("\n\n== ft_get_index ==\n");
	ft_get_index(stack_a);
	ft_print_nbrs(a);

	//Algoritmo simple
	ft_printf("\n\n== alg1 ==\n");
	ft_printf("pila a: "); ft_print_nums(a); ft_printf("\n");
	ps_alg1(&a, &b);
	ft_printf("pila a: "); ft_print_nums(a);
	ft_printf("\npila b: "); ft_print_nums(b);

	ft_printf("\n END \n");

	return (0);
}
