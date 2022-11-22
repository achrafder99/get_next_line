/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:51:35 by adardour          #+#    #+#             */
/*   Updated: 2022/11/20 14:34:50 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

char		*concatenation(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
int			len(char *line);
char		*cut_string(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char		*ft_strdup(const char *s1);

typedef struct next_line
{
	char	*buffer;
	char	*return_line;
	ssize_t	bytes;
}			t_next_line;

#endif