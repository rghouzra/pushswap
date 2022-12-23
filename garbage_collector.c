/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:59:42 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/22 17:44:13 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_clean(char **s)
{
	strings_cleaner(s);
	ft_putstr("Error\n", 2);
	exit(1);
}

void	strings_cleaner(char **s)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*s)
		return ;
	while (*(s + i))
	{
		tmp = *(s + i);
		free(tmp);
		i++;
	}
	free(s);
	s = NULL;
}
