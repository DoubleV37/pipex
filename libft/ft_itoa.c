/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 11:13:02 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:16 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_size_nb(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		nb /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_convert(char *str, int nb)
{
	int		i;
	int		tmp;
	char	nb_char;

	i = 0;
	if (nb < 0)
	{
		str[0] = '-';
		str[1] = '\0';
		nb *= -1;
	}
	if (nb >= 10)
	{
		tmp = nb % 10;
		nb /= 10;
		ft_convert(str, nb);
	}
	else
		tmp = nb;
	nb_char = tmp + '0';
	while (str[i])
		i++;
	str[i] = nb_char;
	str[i + 1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sizenb;

	if (n == 2147483647)
	{
		str = ft_strdup("2147483647");
		if (str == NULL)
			return (NULL);
	}
	else if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		if (str == NULL)
			return (NULL);
	}
	else
	{
		sizenb = ft_count_size_nb(n);
		str = malloc(sizeof(char) * (sizenb + 1));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		str = ft_convert(str, n);
	}
	return (str);
}
