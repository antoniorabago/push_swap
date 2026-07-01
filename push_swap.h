/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabago- <arabago-@student.42madrid.c      +#+  +:+       +#+        */
/*       seoliver <seoliver@student.42madrid.com> +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 17:54:12 by seoliver          #+#    #+#             */
/*   Updated: 2026/07/01 15:42:22 by arabago-         ###   ########.fr       */
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
# include <limits.h>

typedef struct s_node
{
	int				num;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*start;
	int				size;
}	t_stack;

typedef struct s_parse
{
	double	disorder;
	int		bench;
	int		i;
	int		algoritm;
}	t_parse;

typedef struct s_limit
{
	int	max;
	int	rotate_limit;
}	t_limit;

void	sa(t_stack *sta, int *op_count);
void	sb(t_stack *stb, int *op_count);
void	ss(t_stack *sta, t_stack *stb, int *op_count);
void	pa(t_stack *sta, t_stack *stb, int *op_count);
void	pb(t_stack *sta, t_stack *stb, int *op_count);
void	ra(t_stack *sta, int *op_count);
void	rb(t_stack *stb, int *op_count);
void	rr(t_stack *sta, t_stack *stb, int *op_count);
void	rra(t_stack *sta, int *op_count);
void	rrb(t_stack *stb, int *op_count);
void	rrr(t_stack *sta, t_stack *stb, int *op_count);
void	ps_set_index(t_stack *st);
void	ps_alg_small(t_stack *sta, t_stack *stb, int *op_count);
void	ps_alg_simple(t_stack *sta, t_stack *stb, int *op_count);
void	ps_alg_medium(t_stack *sta, t_stack *stb, int *op_count);
void	ps_alg_complex(t_stack *sta, t_stack *stb, int *op_count);
double	ps_stack_disorder(t_stack *st);
int		ps_parsing(char **argv, t_stack *sta, t_stack *stb, t_parse *param);
int		ps_valid_numbers(char *num, t_stack *st);
int		ps_print_error(void);
int		ps_get_argc(char **argv);
void	ps_stack_init(t_stack *st);
void	ps_free_numbers(char **numbers);
void	ps_bench(t_parse param, t_stack *sta, int *opc);
t_node	*ft_lstnew(int num);
t_node	*ft_lstlast(t_node *lst);
t_node	*ft_lst_secondtolast(t_node *lst);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_lstclear(t_node **lst);
void	ft_print_nbrs(t_node *lst);
void	ft_print_nums(t_node *lst);
long	ft_atol(const char *str);
char	**ft_split(char const *s, char c);
int		ft_printf(char const *s, ...);	
int		ft_printf_fd(int fd, char const *s, ...);
int		ft_printptr(unsigned long ptr, int fd);
int		ft_printnbr_base_u(unsigned long long nbr, int base_len, int fd);
int		ft_printnbr_base(long long nbr, char *base, int base_len, int fd);
int		ft_printstr(char *str, int fd);

#endif
