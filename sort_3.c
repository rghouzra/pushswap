/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:02:49 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:02:53 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	three_sorted(t_list *stack_a)
{
	return ((stack_a)->index == (stack_a)->next->index - 1
		&& (stack_a)->index == (stack_a)->next->next->index - 2);
}

void	sec_sorting_3(t_list **stack_a, t_instruction **move)
{
	if ((*stack_a)->index == (*stack_a)->next->index - 1
		&& (*stack_a)->index == (*stack_a)->next->next->index + 1)
		ft_moveadd_back(move, revers_rotat_a(stack_a, 1));
	else if ((*stack_a)->index == (*stack_a)->next->index + 1
		&& (*stack_a)->index == (*stack_a)->next->next->index + 2)
	{
		ft_moveadd_back(move, swap_ab(stack_a, 1));
		ft_moveadd_back(move, revers_rotat_a(stack_a, 1));
	}
	else if ((*stack_a)->index == (*stack_a)->next->index - 2
		&& (*stack_a)->index == (*stack_a)->next->next->index - 1)
	{
		ft_moveadd_back(move, revers_rotat_a(stack_a, 1));
		ft_moveadd_back(move, swap_ab(stack_a, 1));
	}
}

void	sorting_3(t_list **stack_a, t_instruction **move)
{
	int	size;

	size = get_stack_size(*stack_a);
	if (size == 3 && !three_sorted(*stack_a))
	{
		if ((*stack_a)->index == (*stack_a)->next->index + 1
			&& (*stack_a)->index == (*stack_a)->next->next->index - 1)
			ft_moveadd_back(move, swap_ab(stack_a, 1));
		if ((*stack_a)->index == (*stack_a)->next->index + 2
			&& (*stack_a)->index == (*stack_a)->next->next->index + 1)
			ft_moveadd_back(move, rotate_a(stack_a, 1));
		if ((*stack_a)->index == (*stack_a)->next->index - 1
			&& (*stack_a)->index == (*stack_a)->next->next->index +1)
			ft_moveadd_back(move, revers_rotat_a(stack_a, 1));
		else
			sec_sorting_3(stack_a, move);
	}
	else if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			ft_moveadd_back(move, swap_ab(stack_a, 1));
	}
}
