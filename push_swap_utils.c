/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:15:58 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 19:16:00 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1 * sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (sign * nbr);
}

void	ft_print_nbrs(t_node *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("Num: %i index: %i\n", lst->num, lst->index);
		lst = lst->next;
	}
}

void	ft_print_nums(t_node *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		ft_printf("%i ", lst->num);
		lst = lst->next;
	}
}
