/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:39:53 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/18 14:39:55 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_list *s)
{
	if (!s)
		return (1);
	return (0);
}

bool	issorted(t_list *s, int size)
{
	if (size == 1)
		return (true);
	while (s->next)
	{
		if (s->index > s->next->index)
			return (false);
		s = s->next;
	}
	return (true);
}
