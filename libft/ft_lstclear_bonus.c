/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:36:01 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 17:02:46 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*actual;

	if (lst && (*del))
	{
		actual = *lst;
		tmp = actual->next;
		while (actual != NULL)
		{
			tmp = actual->next;
			ft_lstdelone(actual, (*del));
			actual = tmp;
		}
		*lst = NULL;
	}
}
