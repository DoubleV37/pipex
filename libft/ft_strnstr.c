/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 14:23:32 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:04 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big == NULL && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *) big);
	while (big[i] && i < len)
	{
		while (big[i + j] && big[i + j] == little[j] && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return ((char *) &big[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
