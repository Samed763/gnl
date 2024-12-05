/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:51:35 by sadinc            #+#    #+#             */
/*   Updated: 2024/12/05 12:47:57 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t ft_strlen(char *s1)
{
	size_t i;

	i = 0;
	while (s1[i] != '\0')
		i++;
	return (i);
}

int get_newline_index(char * remainder)
{
	int i;

	i = 0;
	if(!remainder)
		return (0);
	while (remainder[i] != '\0' && remainder[i] != '\n')
		i++;

	return (i);
}

char *ft_find_newline(char *s)
{
	int i;

	i=0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i] != '\0')
	{
		if(s[i] == '\n')
			return (s + i);
		i++;
	}
	return (NULL);
}

char *ft_strjoin(char *s1,char* s2)
{
	int		i;
	int		j;
	char	*joined_str;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	joined_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined_str)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != '\0')
		joined_str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		joined_str[i++] = s2[j++];
	joined_str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (joined_str);
}