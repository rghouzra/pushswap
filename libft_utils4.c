/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:00 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:01:03 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	if (fd == 2)
		exit(1);
}

int	index_in_stack(t_list *s, int needle)
{
	int	index;

	index = 0;
	while (s)
	{
		if (needle == s->index)
			return (index);
			index++;
			s = s->next;
	}
	return (-1);
}

int	get_stack_size(t_list *s)
{
	int	counter;

	counter = 0;
	if (!s)
		return (0);
	while (s)
	{
			counter++;
			s = s->next;
	}
	return (counter);
}

t_instruction	*ft_newmove(char *content)
{
	t_instruction	*new;

	new = malloc(sizeof (t_instruction));
	if (new)
	{
			new->move = content;
			new->next = NULL;
	}
	return (new);
}

void	ft_moveadd_back(t_instruction **lst, t_instruction *new)
{
	t_instruction	*copy;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy->next)
			copy = copy->next;
	copy->next = new;
}
