/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:27:45 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:12 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*base;
	unsigned char	*res;

	if (dest == NULL && src == NULL)
		return (NULL);
	base = (unsigned char *)src;
	res = (unsigned char *)dest;
	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			res[i] = base[i];
			i++;
		}
		return (res);
	}
	while (i < n)
	{
		res[n - (i + 1)] = base[n - (i + 1)];
		i++;
	}
	return (res);
}
