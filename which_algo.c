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

void	which_algo(t_list **a, int *size, t_instruction **move)
{
	if (!*a)
		return ;
	if (issorted(*a, *size))
		return ;
	if (*size > 3)
	{
		if (*size == 5)
			sort_5(a, move);
		else
			sort_stack(a, size, move);
	}
	else
		sorting_3(a, move);
}
