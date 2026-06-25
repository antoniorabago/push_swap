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

static void ps_select_alg(char *argv)
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

static int	ps_valid_number(char *argv, t_node *lst)
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

static int ps_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static void ps_stack_init(t_stack *st)
{
	st->start = NULL;
	st->size = 0;
}


static int ps_parsing(int argc, char **argv, int *i, int *bench)
{
	//Al menos dos argumentos
	if (argc < 3)
	{
		ft_putstr("Error: Provide at least 2 numbers as args.");
		return (1);
	}

	//Detectar Benchmark
	*i = 1;
	*bench = 0;
	if (strcmp(argv[*i], "--bench") == 0)
	{
		*bench = 1;
		(*i)++;
	}

	//Validar números (sin duplicados)
	if(!ps_valid_number(argv[*i], NULL))
		return (ps_print_error());

	return (0);
}

static int ps_load_data(int argc, char **argv, int *i, t_stack *sta, t_stack *stb)
{
	//Inicializar las pilas
	ps_stack_init(sta);
	ps_stack_init(stb);
	
	//Cargar datos en la pila a
	while (*i < argc)
	{
		if(!ps_valid_number(argv[*i], sta->start))
			return (ps_print_error());

		ft_lstadd_back(&sta->start, ft_lstnew(ft_atoi(argv[*i])));
		(*i)++;
		sta->size++;
	}
	printf("El primer elemento de la pila a es: %d \n", (sta->start)->num);
	printf("El último elemento de la pila a es: %d \n", ft_lstlast(sta->start)->num);
	printf("El tamaño de la pila a es: %d \n", sta->size);
	return (0);
}


int	main(int argc, char **argv)
{
	int	i;
	int bench;
	double disorder;
	int pa_count;
	int pb_count;
	int ra_count;
	t_stack stack_a;
	t_stack stack_b;

	//Parsing
	if (ps_parsing(argc, argv, &i, &bench))
		return (1);

	// TODO: add adaptative by default
	//Seleccionar algoritmo
	if (argv[i][0] == '-' && argv[i][1] == '-')
	{
		ps_select_alg(argv[i]);
		i++;
	}

	//Inicializar pilas y cargar números en la pila a
	if (ps_load_data(argc, argv, &i, &stack_a, &stack_b))
		return (1);

	//Indice de Desorden
	disorder = ps_stack_disorder(&stack_a);
	
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
	if (bench == 1)
	{
		ft_printf("\nBench \n");
		//Se usa printf porque en ft_printf no existe %f
		printf("[bench] disorder: %.2f%%\n", disorder * 100);
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
