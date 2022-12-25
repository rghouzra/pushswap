/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:39:53 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/25 16:25:12 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list *s)
{
	if (!s)
		return (1);
	return (0);
}

bool	issorted(t_list *s, int size)
{
	if (size == 1)
		return (true);
	while (s->next)
	{
		if (s->index > s->next->index)
			return (false);
		s = s->next;
	}
	return (true);
}

int	second_try(t_list **a, int s, t_instruction **move)
{
	t_algo	x;

	x.copy = dup_list(*a);
	x.tmp = dup_move(*move);
	x.size = s;
	sort_stack(&x.copy, &x.size, &x.tmp, 7);
	if (ft_lstsize(x.tmp) - read_moves(x.tmp) <= 5500)
		return (ft_lstclear(&x.copy, &x.tmp), 7);
	ft_lstclear(&x.copy, &x.tmp);
	x.copy = dup_list(*a);
	x.tmp = dup_move(*move);
	x.size = s;
	sort_stack(&x.copy, &x.size, &x.tmp, 8);
	if (ft_lstsize(x.tmp) - read_moves(x.tmp) <= 5500)
		return (ft_lstclear(&x.copy, &x.tmp), 8);
	ft_lstclear(&x.copy, &x.tmp);
	x.copy = dup_list(*a);
	x.tmp = dup_move(*move);
	x.size = s;
	sort_stack(&x.copy, &x.size, &x.tmp, 9);
	if (ft_lstsize(x.tmp) - read_moves(x.tmp) <= 5500)
		return (ft_lstclear(&x.copy, &x.tmp), 9);
	return (ft_lstclear(&x.copy, &x.tmp), 6);
}
