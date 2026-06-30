#include "push_swap.h"

static int	ps_is_number(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	if (num[i] == '\0')
		return (0);
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	ps_valid_int(char *num)
{
	long	number;

	number = ft_atol(num);
	if (number < INT_MIN || number > INT_MAX)
	{
		printf("El numero no es un entero: %ld \n", number);
		return (1);
	}
	return (0);
}

static int	ps_valid_duplicates(char *num, t_stack *st)
{
	t_node	*lst;

	lst = st->start;
	while (lst)
	{
		if (lst->num == ft_atol(num))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	ps_valid_numbers(char *num, t_stack *st)
{
	if (!ps_is_number(num))
	{
		printf("Esta cadena no es un número: %s\n", num);
		return (1);
	}
	if (ps_valid_int(num))
		return (1);
	if (ps_valid_duplicates(num, st))
	{
		printf("Se ha encontrado duplicado el número: %s\n", num);
		return (1);
	}
	return (0);
}
