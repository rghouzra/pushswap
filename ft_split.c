/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 05:59:15 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/08 05:59:19 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_in_sep(char cs, char c)
{
	if (cs == c)
		return (1);
	return (0);
}

static char	*ft_words(const char *s, char sep)
{
	size_t	i;
	size_t	length;
	char	*word;

	length = 0;
	i = 0;
	while (*(s + length) && !str_in_sep(*(s + length), sep))
		length++;
	word = (char *)malloc((length + 1) * sizeof (char));
	while (i < length)
	{
		*(word + i) = *(s + i);
		i++;
	}
	*(word + i) = '\0';
	return (word);
}

static void	to_strings(char **strings, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (str_in_sep(*s, c) && *s)
			s++;
		if (*s)
		{
			strings[i++] = ft_words(s, c);
			s++;
		}
		while (!str_in_sep(*s, c) && *s)
			s++;
	}
	strings[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	str_count;
	char	**strings;

	str_count = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	while (1)
	{
		while (str_in_sep(*(s + i), c) && *(s + i))
			i++;
		if (*(s + i) == '\0')
			break ;
		str_count++;
		while (!str_in_sep(*(s + i), c) && *(s + i))
			i++;
	}
	str_count++;
	strings = (char **)malloc(str_count * sizeof (char *));
	if (!strings)
		return (NULL);
	to_strings(strings, s, c);
	return (strings);
}
