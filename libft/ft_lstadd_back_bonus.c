/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:48:58 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/11 13:52:04 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lststart;

	if (*lst)
	{
		lststart = ft_lstlast(*lst);
		lststart->next = new;
	}
	else if (!lst)
		return ;
	else
		*lst = new;
}
