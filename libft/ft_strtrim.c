/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:37:56 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 08:35:05 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getstart(char const *str, char const *set)
{
	size_t	istart;
	int		i;

	i = 0;
	istart = 0;
	while (str[istart] && set[i])
	{
		if (str[istart] == set[i])
		{
			istart++;
			i = 0;
		}
		else
			i++;
	}
	return (istart);
}

static size_t	ft_getend(char const *str, char const *set)
{
	size_t	iend;
	int		i;

	i = 0;
	iend = ft_strlen(str) - 1;
	while (iend > 0 && set[i])
	{
		if (str[iend] == set[i])
		{
			iend--;
			i = 0;
		}
		else
			i++;
	}
	return (iend);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	istart;
	size_t	iend;
	char	*str;

	if (s1)
	{
		istart = ft_getstart(s1, set);
		iend = ft_getend(s1, set);
		if (iend - istart > 0 || iend - istart == 0)
		{
			str = ft_substr(s1, istart, (iend - istart + 1));
			if (str != NULL)
				return (str);
		}
	}
	str = ft_strdup("");
	return (str);
}
