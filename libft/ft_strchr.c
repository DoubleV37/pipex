/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:22:34 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:34:53 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *) s;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (res + i);
		i++;
	}
	if (s[i] == (char) c)
		return (res + i);
	return (NULL);
}
