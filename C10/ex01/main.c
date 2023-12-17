/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 07:22:22 by blarger           #+#    #+#             */
/*   Updated: 2023/10/12 14:10:15 by blarger          ###   ########.fr       */
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
#define BUFFER_SIZE 1081

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

char	*read_from_file(char *filename, char *buffer)
{
	int		fd;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		close(fd);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	return (buffer);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (0);
}

void	ft_show_file(char *input, char *buffer)
{
	char	*output;

	output = read_from_file(basename(input), buffer);
	if (output == NULL)
	{
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
	}
	else
		ft_putstr(output);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	buffer[BUFFER_SIZE];

	i = 1;
	if (argc == 1)
		ft_show_file(read_file_from_input(buffer), buffer);
	else if (argc >= 2)
	{
		while (i < argc)
		{
			ft_show_file(argv[i], buffer);
			i++;
		}
	}
	return (0);
}
