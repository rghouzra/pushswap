/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 08:55:17 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/16 07:32:14 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_buffer(int fd, char *saved)
{
	char	*buffer;
	int		readed;

	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!has_nl(saved) && readed)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), NULL);
		if (readed == 0)
			return (free(buffer), saved);
		*(buffer + readed) = '\0';
		saved = ft_strcolect(saved, buffer);
	}
	free(buffer);
	return (saved);
}

static char	*get_line(char *buff)
{
	int		i;
	char	*line;
	int		j;

	j = 0;
	i = 0;
	if (*buff == '\0')
		return (NULL);
	while (*(buff + i) && *(buff + i) != '\n')
		i++;
	if (*(buff + i) == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		*(line + j) = *(buff + j);
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*get_remain(char *buffer)
{
	int		i;
	int		j;
	char	*remain;

	i = 0;
	j = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (*(buffer + i) == '\n')
		i++;
	if (*(buffer + i) == 0)
		return (free(buffer), NULL);
	remain = malloc(ft_stren(buffer) - i + 1);
	if (!remain)
		return (NULL);
	while (j < (ft_stren(buffer) - i))
	{
		*(remain + j) = *(buffer + i + j);
		j++;
	}
	*(remain + j) = 0;
	free(buffer);
	return (remain);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (fd < 0)
		return (NULL);
	saved = read_buffer(fd, saved);
	if (!saved)
		return (NULL);
	line = get_line(saved);
	saved = get_remain(saved);
	return (line);
}
