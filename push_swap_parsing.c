/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 17:08:07 by arabago-          #+#    #+#             */
/*   Updated: 2026/06/18 17:08:09 by arabago-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ps_select_alg(char **argv, int i, t_parse *param)
{
	if (strcmp(argv[i], "--simple") == 0)
	{
		param->algoritm = 1;
		return (i);
	}
	else if (strcmp(argv[i], "--medium") == 0)
	{
		param->algoritm = 2;
		return (i);
	}
	else if (strcmp(argv[i], "--complex") == 0)
	{
		param->algoritm = 3;
		return (i);
	}
	else if (strcmp(argv[i], "--adaptive") == 0)
	{
		param->algoritm = 0;
		return (i);
	}
	else
		param->algoritm = 0;
	return (0);
}

static int	ps_process_numbers(char **argv, t_stack *sta, t_parse *param)
{
	char	**numbers;
	int		nums;

	if (argv[param->i][0] == '\0'
		|| (argv[param->i][0] == ' ' && argv[param->i][1] == '\0'))
		return (ps_print_error());
	numbers = ft_split(argv[param->i], ' ');
	nums = 0;
	while (numbers[nums] != NULL)
	{
		if (ps_valid_numbers(numbers[nums], sta))
		{
			ps_free_numbers(numbers);
			return (ps_print_error());
		}
		ft_lstadd_back(&sta->start, ft_lstnew(ft_atol(numbers[nums])));
		sta->size++;
		nums++;
	}
	ps_free_numbers(numbers);
	return (0);
}

static int	ps_load(char **argv, t_stack *sta, t_stack *stb, t_parse *param)
{
	int	argc;

	ps_stack_init(sta);
	ps_stack_init(stb);
	argc = ps_get_argc(argv);
	while (param->i < argc)
	{
		if (ps_process_numbers(argv, sta, param))
			return (1);
		param->i++;
	}
	return (0);
}

static void	ps_set_param(int argc, char **argv, t_parse *param)
{
	int	found;
	int	position;

	found = 0;
	position = 1;
	while (position < argc && position <= 2)
	{
		if (strcmp(argv[position], "--bench") == 0)
		{
			param->bench = 1;
			param->i++;
		}
		if (found == 0 && ps_select_alg(argv, position, param) > 0)
		{
			found = 1;
			param->i++;
		}
		position++;
	}
}

int	ps_parsing(char **argv, t_stack *sta, t_stack *stb, t_parse *param)
{
	int	argc;

	param->i = 1;
	param->bench = 0;
	param->algoritm = 0;
	argc = ps_get_argc(argv);
	if (argc == 1)
		return (1);
	ps_set_param(argc, argv, param);
	if (ps_load(argv, sta, stb, param))
		return (1);
	return (0);
}
