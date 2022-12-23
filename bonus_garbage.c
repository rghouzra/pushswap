/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_garbage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:38:39 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/22 17:39:38 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_cleaner(char *s, t_list **lst, t_list **lst2)
{
	t_list	*tmp;

	(void)s;
	if (!*lst)
		exit(1);
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
	free(*lst);
	if (!*lst2)
		exit(1);
	while (*lst2)
	{
		tmp = *lst2;
		(*lst2) = (*lst2)->next;
		free(tmp);
	}
	free(*lst2);
	exit(1);
}
