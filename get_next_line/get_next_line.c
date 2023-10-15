/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:39:26 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/12 20:18:51 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *nextline;
    t_list  *list = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &, 0) < 0)
        return (NULL);
    list_create(&list, fd);
    if (list == NULL)
        return (NULL); 
    nextline = get_line(list);
	clear_memory(&list);
	return (next_line);
}
