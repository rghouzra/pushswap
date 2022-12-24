/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:26:49 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/24 11:19:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_struct_init(t_sorting *p, int size)
{
	p->c = 0;
	p->size_b = 0;
	p->b = NULL;
	if (size <= 100)
		p->s = 3;
	else
		p->s = 5;
}

void	short_b_sort(t_sorting *x, t_instruction **move)
{
	if (x->size_b >= 2)
	{
		if (x->b->index <= x->pv2
			&& x->b->index < x->b->next->index)
			ft_moveadd_back(move, rotate_a(&x->b, 2));
		if (x->b->index == x->b->next->index - 1)
			ft_moveadd_back(move, swap_ab(&x->b, 2));
	}
}

void	sort_stack(t_list **a, int *size, t_instruction **moves, int div)
{	
	t_sorting	x;

	sort_struct_init(&x, *size);
	while (*size > 3 && !issorted(*a, *size))
	{
		x.pv1 = ((*size / (div))) + x.size_b;
		x.pv2 = (*size / ((div) * 2)) + x.size_b;
		while (x.c <= x.pv1)
		{
			short_b_sort(&x, moves);
			if ((*a)->index <= x.pv1)
			{
				ft_moveadd_back(moves, push_ab(a, &x.b, 2));
				increment(&x.c, &x.size_b, size);
			}
			if ((*a)->index > x.pv1 && ft_lstlast(*a)->index <= x.pv1)
				ft_moveadd_back(moves, revers_rotat_a(a, 1));
			if ((*a)->index > x.pv1)
				ft_moveadd_back(moves, rotate_a(a, 1));
		}
	}
	second_sort(a, &x.b, moves);
}

void	second_sort(t_list **a, t_list**b, t_instruction **move)
{
	int	max;
	int	b_size;
	int	index;

	sorting_3(a, move);
	b_size = get_stack_size(*b);
	max = b_size - 1;
	while (b_size)
	{
		index = index_in_stack(*b, max);
		if ((*b)->index != max && index > max / 2)
			ft_moveadd_back(move, revers_rotat_a(b, 2));
		if ((*b)->index != max && index <= max / 2)
			ft_moveadd_back(move, rotate_a(b, 2));
		if (max == (*b)->index)
		{
			ft_moveadd_back(move, push_ab(b, a, 1));
			b_size--;
			max--;
		}
	}
}
