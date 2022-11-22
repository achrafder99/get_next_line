/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winkh99 <winkh99@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:51:35 by adardour          #+#    #+#             */
/*   Updated: 2022/11/22 18:32:34 by winkh99          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <limits.h>

char	*concatenation(char *s1, char  *s2);
size_t		ft_strlen(char *s);
int			len(char *line);
char		*cut_string(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char		*ft_strdup(char *s1);

typedef struct next_line
{
	char	*buffer;
	char	*return_line;
	ssize_t	bytes;
}			t_next_line;

#endif