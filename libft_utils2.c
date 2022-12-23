/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 06:00:28 by rghouzra          #+#    #+#             */
/*   Updated: 2022/12/22 18:37:43 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
		i++;
	return (i);
}

long	ft_atoi(const char *nptr)
{
	int		sign;
	int		i;
	long	n;

	n = 0;
	i = 0;
	sign = 1;
	while ((*(nptr + i) >= 9 && *(nptr + i) <= 13) || *(nptr + i) == ' ')
			i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		if (*(nptr + i) == '-')
				sign = -1;
		i++;
	}
	while ((*(nptr + i) >= '0' && *(nptr + i) <= '9') && *(nptr + i))
	{
			n *= 10;
			n += *(nptr + i) - 48;
			i++;
	}
	return (n * sign);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstdellast(t_list **a)
{
	t_list	*end ;
	t_list	*prev ;

	end = *a;
	prev = NULL;
	while (end->next)
	{
		prev = end;
		end = end->next;
	}
	prev->next = NULL;
	free(end);
}

char	*ft_strcollect(char *s1, char *s2)
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
	strings = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof (char));
	if (!strings)
		return (strings);
	while (s1[++i])
		*(strings + i) = *(s1 + i);
	while (*(s2 + j))
		strings[i++] = s2[j++];
	*(strings + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (free(s1), strings);
}
