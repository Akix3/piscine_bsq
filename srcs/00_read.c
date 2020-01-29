/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoshida <ayoshida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 14:44:24 by ayoshida          #+#    #+#             */
/*   Updated: 2020/01/29 17:54:51 by ayoshida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_tools.h"
#include <stdio.h>

int		count(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		num;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (count(src) + 1));
	if (dest == NULL)
		return (NULL);
	num = 0;
	while (src[num] != '\0')
	{
		dest[num] = src[num];
		num++;
	}
	dest[num] = '\0';
	return (dest);
}

char	*ft_strjoin(char *dest, char *src)
{
	int cd;
	int cs;
	char *c;

	cd = count(dest);
	cs = count(src);
	c = (char *)malloc(sizeof(char) * (cd + cs) + 1);
	cd = 0;
	while (dest[cd])
	{
		c[cd] = dest[cd];
		cd++;
	}
	cs = 0;
	while (src[cs])
	{
		c[cd + cs] = src [cs];
		cs++;
	}
	c[cd + cs] = '\0';
	return (c);
}

char	*ft_read(char *src)
{
	int fd;
	char buff[100];
	char *ptr;
	int i;

	fd = open(src, O_RDONLY);
	if (fd == -1)
		return (0);
	*ptr = '\0';
	i = 0;
	while ((i = read(fd, buff, 1)) != 0)
	{
		buff[i] = '\0';
		if(ptr == NULL)
			ptr = ft_strdup(buff);
		else
			ptr = ft_strjoin(ptr,buff);
	}
	if (i == -1)
		return (0);
	ptr[i] = '\0';
	return (ptr);
}

int		main(int argc, char *argv[])
{
	printf("%s", ft_read(argv[1]));
	return (0);
}