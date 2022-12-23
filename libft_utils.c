/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:00:15 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:00:18 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, t_instruction **move)
{
	t_list			*tmp;
	t_instruction	*tmp2;

	if (!*lst || !*move)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
		tmp = NULL;
	}
	free(*lst);
	*lst = NULL;
	while (*move)
	{
		tmp2 = *move;
		(*move) = (*move)->next;
		free(tmp2);
	}
	free(*move);
	*move = NULL;
}	

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof (t_list));
	if (new)
	{
		new->index = content ;
		new->next = NULL;
	}
	return (new);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		counter;

	last = lst;
	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	while (counter > 1)
	{
		last = last->next;
		counter--;
	}
	return (last);
}
