/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_instruction_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:39:05 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/18 14:39:16 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_second_go_to(char *s1, t_list **a, t_list **b)
{
	if (!ft_strncmp(s1, "rrr\n", ft_strlen("rrr\n")))
	{
		if (get_stack_size(*b) >= 2)
			revers_rotat_a(b, -1);
		if (get_stack_size(*a) >= 2)
			revers_rotat_a(a, -1);
		return ;
	}
	else
	{
		write(2, "Error\n", ft_strlen("Error\n"));
		exit_with_cleaner(s1, a, b);
		return ;
	}
}

void	second_go_to(char *s1, t_list **a, t_list **b)
{
	if (!ft_strncmp(s1, "rr\n", ft_strlen("rr\n")))
	{
		if (get_stack_size(*a) >= 2)
			rotate_a(a, -1);
		if (get_stack_size(*b) >= 2)
			rotate_a(b, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "ss\n", ft_strlen("ss\n")))
	{
		if (get_stack_size(*a) >= 2)
			swap_ab(a, -1);
		if (get_stack_size(*b) >= 2)
			swap_ab(b, -1);
		return ;
	}
	divide_second_go_to(s1, a, b);
}

void	divide_go_to_instruction(char *s1, t_list **a, t_list **b)
{
	if (!ft_strncmp(s1, "sa\n", ft_strlen("sa\n")))
	{
		if (get_stack_size(*a) >= 2)
			swap_ab(a, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "sb\n", ft_strlen("sb\n")))
	{
		if (get_stack_size(*b) >= 2)
			swap_ab(b, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "rra\n", ft_strlen("rra\n")))
	{
		if (get_stack_size(*a) >= 2)
			revers_rotat_a(a, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "rrb\n", ft_strlen("rrb\n")))
	{
		if (get_stack_size(*b) >= 2)
			revers_rotat_a(b, -1);
		return ;
	}
	second_go_to(s1, a, b);
}

void	go_to_instruction(char *s1, t_list **a, t_list **b)
{
	if (!s1)
		return ;
	if (!ft_strncmp(s1, "ra\n", ft_strlen("ra\n")))
	{
		if (get_stack_size(*a) >= 2)
			rotate_a(a, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "rb\n", ft_strlen("rb\n")))
	{
		if (get_stack_size(*b) >= 2)
			rotate_a(b, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "pa\n", ft_strlen("pa\n")))
	{
		push_ab(b, a, -1);
		return ;
	}
	else if (!ft_strncmp(s1, "pb\n", ft_strlen("pb\n")))
	{
		push_ab(a, b, -1);
		return ;
	}
	divide_go_to_instruction(s1, a, b);
}
