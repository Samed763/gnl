/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:51:31 by sadinc            #+#    #+#             */
/*   Updated: 2024/12/05 12:48:21 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *next_line(char *remainder)
{
    int i;
    int j;
    char *new_remainder;

    i =get_newline_index(remainder);
    if (!remainder[i] && remainder)
    {
        free(remainder);
        return (NULL);
    }
    new_remainder = malloc(ft_strlen(remainder) - i +1 );
	if (!new_remainder)
	{
		free(remainder);
		return (NULL);
	}    
    i++;
    j =0 ;
    while (remainder[i] != '\0')
        new_remainder[j++] = remainder[i++];
    new_remainder[j] = '\0';
    free(remainder);
    return (new_remainder);
}

char *get_the_line(char *remainder)
{
    char *line;
    int i;
    
    i = 0;

    if (!remainder[i])
		return (NULL);
    line = malloc(get_newline_index(remainder) + 2);
    if (!line)
    {
        free(remainder);
        return (NULL);
    }
    while (remainder[i] != '\0' && remainder[i] !='\n')
    {
        line[i] = remainder[i];
        i++;
    }
    if(remainder[i] == '\n')
	{
    	line[i] = remainder[i];
        i++;
    }
    line[i] = '\0';
    return line;
}

char *reader(int fd, char *remainder)
{
    char *buffer;
    int read_len;
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
    {
        free(remainder);
        return (NULL);
    }
    read_len = 1;
    while(!ft_find_newline(remainder) && read_len != 0)
    {
        read_len = read(fd,buffer,BUFFER_SIZE);
        if((!remainder && read_len <= 0) || read_len == -1)
        {
            free(buffer);
            free(remainder);
            return (NULL);
        }
        buffer[read_len] = '\0';
        remainder = ft_strjoin(remainder,buffer);
    }
    free(buffer);
    return (remainder);
}

char *get_next_line(int fd)
{
    char *line;
    static char* remainder;
    
    if(fd < 0 || BUFFER_SIZE <= 0)
    {
        free(remainder);
        return NULL;
    }
    remainder = reader(fd,remainder);
    if(!remainder)
        return (NULL);
    line = get_the_line(remainder);
    remainder = next_line(remainder);
    return (line);
}