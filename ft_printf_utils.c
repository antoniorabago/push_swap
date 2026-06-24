/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:38:09 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/01 14:38:11 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_printnbr_base(long long nbr, char *base, int base_len)
{
	char	c;
	int		n;

	n = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
		n++;
	}
	if (nbr >= base_len)
	{
		n += ft_printnbr_base(nbr / base_len, base, base_len);
	}
	c = base[nbr % base_len];
	write(1, &c, 1);
	n++;
	return (n);
}

int	ft_printnbr_base_u(unsigned long long nbr, int base_len)
{
	char	c;
	int		n;
	char	*base;

	n = 0;
	if (base_len == 16)
		base = "0123456789abcdef";
	else
		base = "0123456789";
	if (nbr >= (unsigned long long)base_len)
		n += ft_printnbr_base_u(nbr / base_len, base_len);
	c = base[nbr % base_len];
	write(1, &c, 1);
	n++;
	return (n);
}

int	ft_printptr(unsigned long ptr)
{
	if (ptr)
		return (ft_printstr("0x")
			+ ft_printnbr_base_u(ptr, 16));
	else
		return (ft_printstr("(nil)"));
}
