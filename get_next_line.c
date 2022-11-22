/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:13:33 by winkh99           #+#    #+#             */
/*   Updated: 2022/11/22 13:43:53 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_if_theres_newline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == 10)
			return (1);
		i++;
	}
	return (-1);
}


static char	*get_next(char *remember_line)
{
	int		i;
	char	*next_line;
	int		length_line;
	int		length;
	
	i = 0;
	length = len(remember_line);
	length_line = ft_strlen(remember_line) - len(remember_line);
	next_line = (char *)malloc((sizeof(char) + length) + 1);
	if (next_line == NULL){
		free(next_line);
		return (NULL);
	}
	next_line = cut_string(remember_line, len(remember_line) + 1, length_line);
	return (next_line);
}

static char	*get_line(char *line)
{
	int i;
	int length_line;
	int j;
	char *str;
	
	i = 0;
	j = 0;
	length_line = len(line);
	if(check_if_theres_newline(line) != 1)
		return (ft_strdup(line));
	else{
		str = malloc(sizeof(char) * length_line + 2);
		if(str == NULL)
			return (NULL);
		while(j < length_line){
			str[j] = *(line + j);
			j++;
		}
		str[j] = '\n';
		str[j + 1] = '\0';
	}
	return (str);
}

char	*get_next_line(int fd)
{
	t_next_line	next;
	static char	*remember_line;

	if(remember_line == NULL)
		remember_line = "";
	next = (t_next_line){.bytes = 1, .buffer = NULL, .return_line = NULL};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (next.bytes != 0 && check_if_theres_newline(remember_line) == -1)
	{
		next.buffer = malloc(BUFFER_SIZE + 1);
		if(next.buffer == NULL){
			free(next.buffer);
			return (NULL);
		}
		next.bytes = read(fd, next.buffer, BUFFER_SIZE);
		if (next.bytes == -1 || (next.bytes == 0 && ft_strlen(remember_line) == 0)) 
		{
			free(next.buffer);
			return (NULL);
		}
		next.buffer[next.bytes] = '\0';
		remember_line = concatenation(remember_line, next.buffer);
		free(next.buffer);
	}
	next.return_line = get_line(remember_line);
	remember_line = get_next(remember_line);
	return (next.return_line);
}

int main(){
	int fd;
	fd = open("test.txt",O_RDONLY);
	printf("%s\n",get_next_line(fd));
	return (0);
}