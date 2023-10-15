/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:28:09 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/12 20:18:55 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clear_memory(t_list **list)

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (NULL == list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(str_len + 1);
	if (NULL == next_str)
		return (NULL);
	copy_str(list, next_str);
	return (next_str);
}

void	list_add(t_list **list, char *buf)
{
	t_list	*new_node;
	t_list	*last_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (NULL == new_node)
		return ;
	if (NULL == last_node)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str_buf = buf;
	new_node->next = NULL;
}



newlinecheck

//done


void	list_create(t_list **list, int fd)
{
	int		readcount;	
	char	*buff;

	while (!newlinecheck(*list))
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ;
		readcount = read(fd, buff, BUFFER_SIZE);
		if (!readcount)
		{
			free(buff);
			return ;
		}
		buff[readcount] = '\0';
		list_add(list, buff);
	}
}


//done

char *get_next_line(int fd)
{
    char *nextline;
    t_list  *list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    list_create(&list, fd);
    if (list == NULL)
        return (NULL); 
    nextline = get_line(list);
	clear_memory(&list);
	return (next_line);
}