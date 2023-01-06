/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:01:55 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:14 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*mem1;
	unsigned char	*mem2;
	size_t			i;

	mem1 = (unsigned char *) s1;
	mem2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (mem1[i] == mem2[i] && i < (n - 1))
		i++;
	return (mem1[i] - mem2[i]);
}
