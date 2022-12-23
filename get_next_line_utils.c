/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:04:29 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/14 09:04:35 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_stren(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

int	has_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (*(str + i))
	{
		if (*(str + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcolect(char *s1, char *s2)
{
	int			i;
	int			j;
	char		*strings;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!(s1))
			return (NULL);
		s1[0] = 0;
	}
	strings = malloc((ft_stren(s1) + ft_stren(s2) + 1) * sizeof (char));
	if (!strings)
		return (strings);
	while (s1[++i])
		*(strings + i) = *(s1 + i);
	while (*(s2 + j))
		strings[i++] = s2[j++];
	*(strings + ft_stren(s1) + ft_stren(s2)) = '\0';
	return (free(s1), strings);
}
