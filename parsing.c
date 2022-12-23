/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:39:46 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/18 14:39:48 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char **av, int ac)
{
	if (!ft_isvalid(av, ac))
		return (-1);
	return (1);
}

int	parsing(t_list **stack, int ac, char **av)
{
	t_parsing	x;

	x.i = -1;
	x.full_arg = NULL;
	if (ft_check_args(av + 1, ac -1) == -1)
		ft_putstr("Error\n", 2);
	while (++x.i < ac)
		x.full_arg = ft_strcollect(ft_strcollect(x.full_arg, av[x.i]), " ");
	if (!x.full_arg)
		exit(1);
	x.s = ft_split(x.full_arg, ' ');
	free(x.full_arg);
	x.full_arg = NULL;
	if (!x.s)
		exit(1);
	x.i = 0;
	if (check_dup(x.s + 1) == -1)
		exit_with_clean(x.s);
	x.size = str_counter(x.s + 1);
	while (x.s[++x.i])
		push(stack, ft_atoi(x.s[x.i]));
	return (strings_cleaner(x.s), x.size);
}

void	indexing(t_list *stack_a, int size)
{
	int		i;
	int		j;
	t_list	*tmp;
	t_list	*ptr;

	i = -1;
	ptr = stack_a;
	while (++i < size)
	{
		j = 0;
		tmp = ptr;
		stack_a->index = i;
		while (j < i)
		{
			if (peek(stack_a) < peek(tmp))
			{
				stack_a->index -= 1;
				tmp->index += 1;
			}
				tmp = tmp->next;
				j++;
		}
		stack_a = stack_a->next;
	}
}
