/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:41:17 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 14:47:41 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (lst != NULL && lst->next != NULL)
	{
		tmp = lst->next;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		return (tmp);
	}
	return (lst);
}
