/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 17:24:02 by arabago-          #+#    #+#             */
/*   Updated: 2026/07/01 17:24:16 by arabago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	ps_get_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

void	ps_stack_init(t_stack *st)
{
	st->start = NULL;
	st->size = 0;
}

void	ps_free_numbers(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}
