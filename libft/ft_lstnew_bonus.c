/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 08:35:55 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/10 13:36:17 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptnewlist;

	ptnewlist = malloc(sizeof(t_list));
	if (ptnewlist == NULL)
		return (NULL);
	(*ptnewlist).content = content;
	(*ptnewlist).next = NULL;
	return (ptnewlist);
}
