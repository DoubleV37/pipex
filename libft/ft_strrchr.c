/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:35:29 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:04 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		tmp;
	char	*res;

	i = 0;
	tmp = -1;
	res = (char *) s;
	while (s[i])
	{
		if (s[i] == (char) c)
			tmp = i;
		i++;
	}
	if (s[i] == (char) c)
		return (res + i);
	if (tmp == -1)
		return (NULL);
	return (res + tmp);
}
