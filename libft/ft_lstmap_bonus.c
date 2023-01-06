/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vviovi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:12:47 by vviovi            #+#    #+#             */
/*   Updated: 2022/10/11 13:50:21 by vviovi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*newlst;
	t_list	*templst;
	void	*valtmp;

	if (!lst || (*f) == NULL || (*del) == NULL)
		return (NULL);
	valtmp = (*f)(lst->content);
	newlst = ft_lstnew(valtmp);
	if (newlst == NULL)
		return (NULL);
	templst = lst->next;
	while (templst != NULL)
	{
		valtmp = (*f)(templst->content);
		tmp = ft_lstnew(valtmp);
		if (tmp == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		templst = templst->next;
	}
	return (newlst);
}
