/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:02:17 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:02:20 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	peek(t_list *s)
{
	if (!s)
		return (0);
	return (s->value);
}

bool	push(t_list **p, int value)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (!n)
		return (false);
	n->value = value;
	n->next = NULL;
	ft_lstadd_back(p, n);
	return (true);
}

int	pop(t_list **p, int *checker)
{
	t_list	*tmp;
	int		r;

	if (!*p)
		return (*checker = -1, -1);
	tmp = *p;
	r = (*p)->value;
	*p = (*p)->next;
	free(tmp);
	*checker = 1;
	return (r);
}
