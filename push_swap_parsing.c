#include "push_swap.h"

static int	ps_print_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	ps_get_argc(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
		i++;
	return (i);
}

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

static void	ps_stack_init(t_stack *st)
{
	st->start = NULL;
	st->size = 0;
}

static void	ps_free_numbers(char **numbers)
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

static int	ps_process_numbers(char **argv, t_stack *sta, t_parse *param)
{
	char	**numbers;
	int		nums;

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

int	ps_parsing(char **argv, t_stack *sta, t_stack *stb, t_parse *param)
{
	int	argc;
	int	found;
	int	position;

	found = 0;
	position = 1;
	param->i = 1;
	param->bench = 0;
	param->algoritm = 0;
	argc = ps_get_argc(argv);
	if (argc == 1)
		return (1);
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
	if (ps_load(argv, sta, stb, param))
		return (1);
	return (0);
}
