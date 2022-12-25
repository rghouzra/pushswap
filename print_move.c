/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:01:39 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/25 16:36:13 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putmove(t_instruction *move)
{
	if (move)
	{
		while (move)
		{
			if (move->next && !ft_strncmp((move)->move, "ra\n", ft_strlen("ra\n"))
				&& !ft_strncmp((move)->next->move, "rb\n", ft_strlen("rb\n")))
			{
				write(1, "rr\n", 3);
				move = (move)->next;
			}
			else if (move->next
				&& !ft_strncmp((move)->move, "rb\n", ft_strlen("rb\n"))
				&& !ft_strncmp((move)->next->move, \
				"ra\n", ft_strlen("ra\n")))
			{
				write(1, "rr\n", 3);
				move = move->next;
			}
			else
				ft_putstr(move->move, 1);
				move = move->next;
		}
	}
}
