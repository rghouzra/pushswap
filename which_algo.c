/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:03:34 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:03:37 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*dup_list(t_list *a)
{
	t_list	*copy;

	if (a == NULL)
		return (NULL);
	else
	{
		copy = malloc(sizeof (t_list));
		if (!copy)
			return (NULL);
		copy->index = a->index;
		copy->next = dup_list(a->next);
	}
	return (copy);
}

t_instruction	*dup_move(t_instruction *move)
{
	t_instruction	*copy;

	if (move == NULL)
		return (NULL);
	else
	{
		copy = malloc(sizeof (t_list));
		if (!copy)
			return (NULL);
		(copy)->move = move->move;
		(copy)->next = dup_move(move->next);
	}
	return (copy);
}

int	read_moves(t_instruction *move)
{
	int	counter;

	counter = 0;
	if (move)
	{
		while (move)
		{
			if (move->next && !ft_strncmp((move)->move, "ra\n", ft_strlen("ra\n"))
				&& !ft_strncmp((move)->next->move, "rb\n", ft_strlen("rb\n")))
			{
				move = (move)->next;
				counter++;
			}
			else if (move->next
				&& !ft_strncmp((move)->move, "rb\n", ft_strlen("rb\n"))
				&& !ft_strncmp((move)->next->move, \
				"ra\n", ft_strlen("ra\n")))
			{
				counter++;
				move = move->next;
			}
			move = move->next;
		}
	}
	return (counter);
}

int	try_the_best_algo(t_list **a, int s, t_instruction **move)
{
	t_algo	x;

	x.copy = dup_list(*a);
	x.tmp = dup_move(*move);
	x.size = s;
	sort_stack(&x.copy, &x.size, &x.tmp, 5);
	if (ft_lstsize(x.tmp) - read_moves(x.tmp) <= 5500)
		return (5);
	ft_lstclear(&x.copy, &x.tmp);
	x.copy = dup_list(*a);
	x.tmp = dup_move(*move);
	x.size = s;
	sort_stack(&x.copy, &x.size, &x.tmp, 6);
	if (ft_lstsize(x.tmp) - read_moves(x.tmp) <= 5500)
		return (6);
	ft_lstclear(&x.copy, &x.tmp);
	x.copy = dup_list(*a);
	x.tmp = dup_move(*move);
	x.size = s;
	sort_stack(&x.copy, &x.size, &x.tmp, 4);
	if (ft_lstsize(x.tmp) - read_moves(x.tmp) <= 5500)
		return (4);
	return (ft_lstclear(&x.copy, &x.tmp), second_try(a, s, move));
}

void	which_algo(t_list **a, int *size, t_instruction **move)
{
	int	div;

	if (!*a)
		return ;
	if (issorted(*a, *size))
		return ;
	if (*size > 3)
	{
		if (*size == 5)
			sort_5(a, move);
		else
		{
			div = try_the_best_algo(a, *size, move);
			fprintf(stderr, "div:%d\n", div);
			sort_stack(a, size, move, div);
		}
	}
	else
		sorting_3(a, move);
}
