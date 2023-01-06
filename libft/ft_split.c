/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:41:21 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/12 10:17:38 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(char const *s, char c)
{
	size_t	i;
	int		nbword;

	i = 0;
	nbword = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nbword++;
		i++;
	}
	return (nbword);
}

static int	getlenword(int pos, char const *str, char c)
{
	int	lenword;

	lenword = 0;
	while (str[pos] != c && str[pos])
	{
		pos++;
		lenword++;
	}
	return (lenword);
}

static int	ft_check_word(char **str, char *word, int j)
{
	int	i;

	if (word)
		return (1);
	else
	{
		i = 0;
		while (i <= j)
		{
			free(str[i]);
			i++;
		}
		free(str);
		return (0);
	}
}

static char	**ft_fill_tab(char **tabstr, char const *s, char const c)
{
	int		i;
	int		j;
	int		lenword;
	char	*word;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			lenword = getlenword(i, s, c);
			word = ft_substr(s, i, lenword);
			if (!ft_check_word(tabstr, word, j))
				return (NULL);
			word[lenword] = '\0';
			i += lenword;
			tabstr[j++] = word;
		}
	}
	tabstr[j] = NULL;
	return (tabstr);
}

char	**ft_split(char const *s, char c)
{
	int		nbword;
	char	**tabstr;

	if (!s)
		return (NULL);
	nbword = ft_countword(s, c);
	tabstr = malloc(sizeof(char *) * (nbword + 1));
	if (tabstr == NULL)
		return (NULL);
	tabstr = ft_fill_tab(tabstr, s, c);
	return (tabstr);
}
