/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:58:34 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/16 21:04:47 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_newline(char *nest)
{
	char	*temp;
	int		i;

	if (!*nest)
		return (NULL);
	i = 0;
	while (nest[i] && nest[i] != '\n')
		i++;
	temp = ft_mem_alloc(i + 2, sizeof(char));
	i = 0;
	while (nest[i] && nest[i] != '\n')
	{
		temp[i] = nest[i];
		i++;
	}
	temp[i] = nest[i];
	return (temp);
}

char	*get_rest(char *nest)
{
	char	*tmp;
	int		i;
	int		index;

	index = 0;
	i = 0;
	while (nest[i] && nest[i] != '\n')
		i++;
	if (!*nest)
	{
		free(nest);
		return (NULL);
	}
	tmp = ft_mem_alloc(ft_strlen(nest) - i + 1, sizeof(char));
	while (nest[i])
		tmp[index++] = nest[++i];
	tmp[index] = '\0';
	free(nest);
	return (tmp);
}

void	*ft_clean(char **nest, char **buffer)
{
	free(*buffer);
	free(*nest);
	*nest = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	int				read_len;
	char			*buffer;
	char			*line;
	static char		*nest;

	read_len = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_mem_alloc(BUFFER_SIZE + 1, sizeof(char));
	while (!(ft_findnl(buffer)) && read_len)
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len == -1)
			return (ft_clean(&nest, &buffer));
		buffer[read_len] = '\0';
		nest = ft_add_nest(nest, buffer);
	}
	line = get_newline(nest);
	nest = get_rest(nest);
	free(buffer);
	return (line);
}
