/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:40:05 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/18 14:40:08 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_list **stack_a, t_instruction **move)
{
	t_sorting	p;

	sort_struct_init(&p, -1);
	while (get_stack_size(*stack_a) > 3)
	{
		p.s = index_in_stack(*stack_a, p.c);
		if ((*stack_a)->index == p.c)
		{
			ft_moveadd_back(move, push_ab(stack_a, &p.b, 2));
			p.size_b++;
			p.c++;
		}
		if (p.s > get_stack_size(*stack_a) / 2)
			ft_moveadd_back(move, revers_rotat_a(stack_a, 1));
		else if (p.s <= get_stack_size(*stack_a) / 2)
			ft_moveadd_back(move, rotate_a(stack_a, 1));
	}
	sorting_3(stack_a, move);
	while (p.size_b > 0)
	{
		ft_moveadd_back(move, push_ab(stack_a, &p.b, 1));
		p.size_b--;
	}
}
