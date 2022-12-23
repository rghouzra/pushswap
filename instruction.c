/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:00:05 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:00:08 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instruction	*swap_ab(t_list **s, int option)
{
	int				tmp;
	t_instruction	*move;

	if (!*s)
		return (NULL);
	tmp = (*s)->index;
	(*s)->index = (*s)->next->index;
	(*s)->next->index = tmp;
	if (option == 1)
			move = ft_newmove("sa\n");
	if (option == 2)
			move = ft_newmove("sb\n");
	return (move);
}

t_instruction	*push_ab(t_list **a, t_list **b, int option)
{
	t_list			*new;
	t_list			*tmp;
	t_instruction	*move;
	t_list			*f;

	if (!*a)
		return (NULL);
	f = *a;
	new = ft_lstnew(((*a)->index));
	new->next = *b;
	*b = new;
	tmp = (*a)->next;
	*a = tmp;
	free(f);
	if (option == 1)
			move = ft_newmove("pa\n");
	if (option == 2)
			move = ft_newmove("pb\n");
	return (move);
}

t_instruction	*rotate_a(t_list **a, int option)
{
	t_list			*bottom;
	t_instruction	*move;
	t_list			*tmp;

	bottom = ft_lstnew((*a)->index);
	tmp = *a;
	(*a) = (*a)->next;
	ft_lstadd_back(a, bottom);
	free(tmp);
	if (option == 1)
			move = ft_newmove("ra\n");
	if (option == 2)
			move = ft_newmove("rb\n");
	return (move);
}

t_instruction	*revers_rotat_a(t_list **a, int option)
{
	t_list			*tmp;
	t_instruction	*move;

	tmp = ft_lstnew((ft_lstlast(*a)->index));
	ft_lstadd_front(a, tmp);
	ft_lstdellast(a);
	if (option == 1)
			move = ft_newmove("rra\n");
	if (option == 2)
			move = ft_newmove("rrb\n");
	return (move);
}
