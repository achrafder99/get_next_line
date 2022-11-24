/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winkh99 <winkh99@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:36:38 by adardour          #+#    #+#             */
/*   Updated: 2022/11/23 22:36:32 by winkh99          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int check_if_there_newline(char *line);
char	*ft_strjoin(char *s1, char const *s2);
char *get_next_line(int fd);
size_t	ft_strlen(const char *s);


#endif