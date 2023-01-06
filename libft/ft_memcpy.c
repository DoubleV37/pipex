/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:31:49 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:12 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*base;
	unsigned char	*res;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	base = (unsigned char *)src;
	res = (unsigned char *)dest;
	while (i < n)
	{
		res[i] = base[i];
		i++;
	}
	return (res);
}
