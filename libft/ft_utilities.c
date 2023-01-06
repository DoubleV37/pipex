/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 09:53:15 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/26 09:56:02 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	size;

	size = 0;
	if (s)
	{
		size = ft_strlen(s);
		write(1, s, size);
	}
	else
	{
		write(1, "(null)", 6);
		size = 6;
	}
	return (size);
}

void	ft_putnbr(int n, int *size)
{
	int		tmp;
	char	c;

	if (n == -2147483648)
		*size += ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			*size += 1;
			n *= -1;
		}
		if (n >= 10)
		{
			tmp = n % 10;
			n /= 10;
			ft_putnbr(n, size);
		}
		else
			tmp = n;
		c = tmp + '0';
		*size += ft_putchar(c);
	}
}

int	ft_putunsignednbr(unsigned int n)
{
	unsigned int	tmp;
	int				size;
	char			c;

	size = 0;
	if (n >= 10)
	{
		tmp = n % 10;
		n /= 10;
		ft_putnbr(n, &size);
	}
	else
		tmp = n;
	c = tmp + '0';
	write(1, &c, 1);
	size++;
	return (size);
}

int	ft_print_pointer(void *address)
{
	int		size;
	size_t	val;

	size = 0;
	if (address)
	{
		write(1, "0x", 2);
		size += 2;
		val = (size_t)address;
		size += ft_putnbr_base(val, "0123456789abcdef");
	}
	else
	{
		write(1, "(nil)", 5);
		size = 5;
	}
	return (size);
}
