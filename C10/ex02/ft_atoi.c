/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:08:07 by blarger           #+#    #+#             */
/*   Updated: 2023/10/12 14:15:42 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <errno.h>
#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*read_file_from_input(void)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc(sizeof(char) * 1080);
	if (!buffer)
		return (0);
	bytes_read = read(STDIN_FILENO, buffer, sizeof(char) * 1080);
	if (bytes_read == -1)
	{
		free(buffer);
		return (0);
	}
	buffer[bytes_read - 1] = '\0';
	return (buffer);
}

int	ft(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
