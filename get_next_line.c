/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adardour <adardour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:36:36 by adardour          #+#    #+#             */
/*   Updated: 2022/11/23 20:05:12 by adardour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char* get_line(char *line){
	char *str;

	int i;
	i = 0;
	while(line[i] != '\0' && line[i] != '\n')
		i++;
	printf("%d\n",i);
	
	return ("");
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
		if (bytes == -1 || (bytes == 0 && ft_strlen(remember_line) == 0)) 
			return (NULL);
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

	if(fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	remember_line = tt(remember_line,fd);
	line = get_line(remember_line);

	return line;
}
int main(){
	int fd;
	fd = open("test.txt",O_RDONLY);
	printf("%s",get_next_line(fd));
	system("leaks a.out");
	return 0;
}