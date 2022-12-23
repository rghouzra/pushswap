/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:39:34 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/18 14:39:37 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	read_instruction(t_list **a, t_list **b)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(0);
		go_to_instruction(buffer, a, b);
		if (!buffer)
			break ;
		free(buffer);
	}
	if (issorted(*a, get_stack_size(*a)))
		ft_putstr("OK\n", 1);
	else
		ft_putstr("KO\n", 1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (ac < 2)
		exit(0);
	stack_a = NULL;
	stack_b = NULL;
	size = parsing(&stack_a, ac, av);
	indexing(stack_a, size);
	read_instruction(&stack_a, &stack_b);
	return (0);
}
