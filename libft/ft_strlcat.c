/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 16:07:57 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:34:56 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	size_src;

	size_src = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (size_src);
	while (dst[i] && i < size)
		i++;
	j = 0;
	if (dst[i] == '\0')
	{
		while (src[j] && (size - 1) > (i + j))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	return (i + size_src);
}
