/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:40:51 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/22 18:37:12 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(char **s)
{
	int		i;
	int		j;
	long	*tab;

	tab = malloc(str_counter(s) * sizeof (long));
	if (!tab)
		return (-1);
	i = -1;
	while (s[++i])
		tab[i] = ft_atoi(s[i]);
	i = -1;
	while (++i < str_counter(s))
	{
		if (tab[i] >= INT_MAX || tab[i] <= INT_MIN)
			return (-1);
		j = i + 1;
		while (j < str_counter(s))
		{
			if (tab[i] == tab[j])
				return (-1);
			j++;
		}
	}
	return (free(tab), 0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t						i;
	unsigned char				*str1;
	unsigned char				*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] && str2[i] && i < n)
	{
		if (((str1[i]) != str2[i]))
			return (str1[i] - str2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (str1[i] - str2[i]);
}
