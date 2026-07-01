/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoliver <seoliver@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 14:38:09 by seoliver          #+#    #+#             */
/*   Updated: 2026/06/01 14:38:11 by seoliver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_printtype(va_list *args, char type, int fd)
{
	char	c;

	if (type == 'c')
	{
		c = (char)va_arg(*args, int);
		return (write(fd, &c, 1));
	}
	else if (type == 's')
		return (ft_printstr(va_arg(*args, char *), fd));
	else if (type == 'd' || type == 'i')
		return (ft_printnbr_base(va_arg(*args, int), "0123456789", 10, fd));
	else if (type == 'u')
		return (ft_printnbr_base_u(va_arg(*args, unsigned int), 10, fd));
	else if (type == 'x')
		return (ft_printnbr_base(va_arg(*args, unsigned int),
				"0123456789abcdef", 16, fd));
	else if (type == 'X')
		return (ft_printnbr_base(va_arg(*args, unsigned int),
				"0123456789ABCDEF", 16, fd));
	else if (type == 'p')
		return (ft_printptr((unsigned long)va_arg(*args, void *), fd));
	else if (type == '%')
		return (ft_printstr("%", fd));
	return (0);
}

int	ft_printf(char const *s, ...)
{
	int		n;
	va_list	args;

	if (!s)
		return (-1);
	n = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			n += ft_printtype(&args, *s, 1);
		}
		else
			n += write(1, s, 1);
		s++;
	}
	va_end(args);
	return (n);
}

int	ft_printf_fd(int fd, char const *s, ...)
{
	int		n;
	va_list	args;

	if (!s)
		return (-1);
	n = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (*s == '\0')
				break ;
			n += ft_printtype(&args, *s, fd);
		}
		else
			n += write(fd, s, 1);
		s++;
	}
	va_end(args);
	return (n);
}
