/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:11 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/16 11:34:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_instruction			*moves;
	t_list					*stack_a;
	int						size;

	if (ac < 2)
		exit(0);
	stack_a = NULL;
	size = parsing(&stack_a, ac, av);
	indexing(stack_a, size);
	which_algo(&stack_a, &size, &moves);
	ft_putmove(moves);
	ft_lstclear(&stack_a, &moves);
	return (0);
}
