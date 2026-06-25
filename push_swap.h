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
# include <stdarg.h>

typedef struct s_node
{
	int		num;
	int		index;
	struct	s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct	s_node	*start;
	int size;
}	t_stack;

void	sa(t_stack *sta);
void	sb(t_stack *stb);
void	ss(t_stack *sta, t_stack *stb);
void	pa(t_stack *sta, t_stack *stb);
void	pb(t_stack *sta, t_stack *stb);
void	ra(t_stack *sta);
void	rb(t_stack *stb);
void	rr(t_stack *sta, t_stack *stb);
void	rra(t_stack *sta);
void	rrb(t_stack *stb);
void	rrr(t_stack *sta, t_stack *stb);
void 	ps_get_index(t_stack *st);
void 	ps_alg_simple(t_stack *sta, t_stack *stb, int *pa_count, int *pb_count, int *ra_count);

t_node	*ft_lstnew(int num);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lst_secondtolast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstclear(t_node **lst);
void	ft_print_nbrs(t_node *lst);
void	ft_print_nums(t_node *lst);

void	ft_putstr(char *str);
int		ft_atoi(const char *str);

int	ft_printf(char const *s, ...);
int	ft_printptr(unsigned long ptr);
int	ft_printnbr_base_u(unsigned long long nbr, int base_len);
int	ft_printnbr_base(long long nbr, char *base, int base_len);
int	ft_printstr(char *str);

#endif