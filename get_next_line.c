/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:36:36 by adardour          #+#    #+#             */
/*   Updated: 2022/11/24 12:59:22 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *get_next(char *next)
{	
	int i;
	i = 0;

	char *str;
	while(next[i] != '\n' && next[i] != '\0')
		i++;
	str = malloc((ft_strlen(next) - i) + 1);
	if(str == NULL){
		free(str);
		return (NULL);
	}
	i++;
	int j;
	j = 0;
	while(next[i] != '\0')
	{
		str[j] = next[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}

static char* get_line(char *line){
	char *str;
	int j;

	int i;
	i = 0;
	if(check_if_there_newline(line) == -1)
		return (line);
	while(line[i] != '\n' && line[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * i + 2);
	if(str == NULL)
	{
		return (NULL);
		free(line);
	}
	j = 0;
	while(j < i){
		str[j] = line[j];
		j++;
	}
	str[j] = '\n';
	str[j + 1] = '\0';
	free(line);
	return (str);
}

char *tt(char *remember_line,int fd){
	
	ssize_t bytes;
	char *buffer;
	char *line;

	bytes = 1;
	while (bytes != 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if(buffer == NULL)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && ft_strlen(remember_line) == 0)){
			free(buffer);
			free(remember_line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin(remember_line, buffer);
		free(buffer);
		free(remember_line);
		remember_line = line;
		if(check_if_there_newline(remember_line) != -1)
			break;
	}
	return (remember_line);
}

char *get_next_line(int fd){
	
	static char *remember_line;
	char *line;
	char *next;
	
	if(fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	remember_line = tt(remember_line,fd);
	if(ft_strlen(remember_line) == 0)
		return (NULL);
	line = get_line(remember_line);
	next = get_next(remember_line);
	remember_line = next;
	return (line);
}
int main(){
	int fd;
	fd = open("test.txt",O_RDONLY);
	char *line;
	int i = 0;
	printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// while(i < 1)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s",line);
	// 	free(line);
	// 	i++;
	// }
	system("leaks a.out");
	return 0;
}