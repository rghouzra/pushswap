/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:00:47 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 06:00:51 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_instruction *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	return (0);
}

void	struct_init(t_isvalid *x)
{
	(*x).j = -1;
	(*x).scnd_flag = 0;
	(*x).third_flag = 0;
	(*x).flag = 0;
}

int	ft_isvalid(char **s, int ac)
{
	t_isvalid	x;

	x.i = -1;
	if (!s)
		return (0);
	while (++x.i < ac)
	{
		struct_init(&x);
		while (s[x.i][++x.j])
		{
			if (ft_isdigit(s[x.i][x.j]))
				x.flag = 1;
			else if (s[x.i][x.j] == 32)
				x.scnd_flag = 1;
			else if (s[x.i][x.j] == '-' && ft_isdigit(s[x.i][x.j + 1]))
				x.flag = 1;
			else
				x.third_flag = 2;
		}
		if ((x.scnd_flag == 1 && x.flag != 1)
			|| x.flag != 1 || x.third_flag == 2)
			return (0);
	}
	return (1);
}

int	str_counter(char **s)
{
	int	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}
