/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:34:00 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/27 08:51:18 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_recursive(size_t nbr, char *base, size_t base_size, int *size)
{
	size_t	tmp;

	tmp = nbr % base_size;
	if (nbr >= base_size)
	{
		nbr -= tmp;
		nbr /= base_size;
		print_recursive(nbr, base, base_size, size);
	}
	write(1, &base[tmp], 1);
	*size += 1;
}

int	ft_putnbr_base(size_t nbr, char *base)
{
	size_t	size;
	int		res_size;
	size_t	convnb;

	size = ft_strlen(base);
	res_size = 0;
	convnb = nbr;
	print_recursive(convnb, base, size, &res_size);
	return (res_size);
}

static int	ft_print_content(const char c, va_list args)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_putchar(va_arg(args, int));
	else if (c == 's')
		size += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		size += ft_print_pointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), &size);
	else if (c == 'u')
		size += ft_putunsignednbr(va_arg(args, unsigned int));
	else if (c == 'x')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		size += ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == '%')
		size += ft_putstr("%");
	else
		return (-1);
	return (size);
}

int	ft_printf(const char *content, ...)
{
	va_list	args;
	int		length_print;
	int		i;

	length_print = 0;
	va_start(args, content);
	i = 0;
	while (content[i])
	{
		if (content[i] == '%')
		{
			i++;
			length_print += ft_print_content(content[i], args);
		}
		else
			length_print += ft_putchar(content[i]);
		i++;
	}
	va_end(args);
	return (length_print);
}
