/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadinc <sadinc@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:51:40 by sadinc            #+#    #+#             */
/*   Updated: 2024/12/04 17:06:27 by sadinc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <stdlib.h>

int		get_newline_index(char *remainder);
size_t	ft_strlen(char *s1);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_find_newline(char *s);

#endif