/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:28:25 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/10/13 09:00:45 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXTLINE_H
# define GET_NEXTLINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 3
#endif

# include <stdio.h>
# include <stdio.h>
#include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	char            *element;
	struct s_list   *next;
}       t_list;

char *get_next_line(int fd);

#endif