/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winkh99 <winkh99@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:51:41 by adardour          #+#    #+#             */
/*   Updated: 2022/11/22 19:07:00 by winkh99          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"

char	*concatenation(char *s1, char  *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	
	if(s1 ==  NULL)
		s1 = ft_strdup("");
	ptr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

int	len(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlen(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
	{
		size++;
	}
	return (size);
}

char	*cut_string(char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start >= (unsigned long)ft_strlen(s))
		return ("");
	substr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[len] = '\0';
	return (substr);
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(ft_strlen(s1) + 1);
	if (ptr == NULL){
		free(ptr);
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
