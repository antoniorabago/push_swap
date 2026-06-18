/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*   By: arabago- <arabago-@student.42madrid.com>     +:+ +:+         +:+     */
/*       seoliver <seoliver@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:54:12 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/17 17:54:13 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

typedef struct s_node
{
	int		num;
	int		index;
	struct	s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct	s_node	*start;
	struct	s_node	*end;
	int size;
}	t_stack;

void	ft_putstr(char *str);
int	ft_atoi(const char *str);

void	sa(t_node **a, t_node **b);
void	sb(t_node **a, t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a, t_node **b);
void	rb(t_node **a, t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a, t_node **b);
void	rrb(t_node **a, t_node **b);
void	rrr(t_node **a, t_node **b);

void ps_alg1(t_node **a, t_node **b);

t_node	*ft_lstnew(int num);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lst_secondtolast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_print_nbrs(t_node *lst);
void	ft_print_nums(t_node *lst);
void ft_get_index(t_node *lst);

int	ft_printf(char const *s, ...);
int	ft_printptr(unsigned long ptr);
int	ft_printnbr_base_u(unsigned long long nbr, int base_len);
int	ft_printnbr_base(long long nbr, char *base, int base_len);
int	ft_printstr(char *str);

#endif