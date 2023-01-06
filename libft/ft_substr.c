/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:49:07 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:06 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size_str;
	size_t	ssize;
	char	*str;

	if (!s)
		return (NULL);
	ssize = ft_strlen(s);
	if (start >= ssize)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	size_str = len;
	if (len > (ssize - start))
		size_str = ssize - start;
	str = malloc(sizeof(char) * (size_str + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s[start], (size_str + 1));
	return (str);
}
