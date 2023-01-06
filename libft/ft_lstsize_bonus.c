/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:24:18 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 14:40:11 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	if (lst != NULL)
	{
		tmp = lst->next;
		while (tmp != NULL)
		{
			tmp = tmp->next;
			i++;
		}
		i++;
	}
	return (i);
}
