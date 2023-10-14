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

char    *from_file_to_buffer(int fd, char *str)
{
    char *buffer;
    int nread;

    // se for pra ler linha a linha usar um stringjoin mas so ler linha a linha ou seja ate encontrar um \n com um memchar ou um str char 
    buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    bytecounter = read(fd, buffer, BUFFER_SIZE);
    if(bytecounter <= 0)
    {
        free(buffer);
        return (NULL);
    }
    buffer[bytecounter] = '\0';
}
//on returning this funckion somewhere else i should keep track of it and free oncenot needed anylonger.

char *get_next_line(int fd)
{
    if (fd < 0 || BUFFER_SIZE < 0)
        return (0);
    else
    //loop write from buffer and everytime it finds a \n writes a \n and changes lien???  How can i read just a line at a time ?
        
}

/*read file line by line and print it no errors tolerated and if there is nothing to read a null should be returnd*/