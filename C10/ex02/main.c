/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:34:15 by blarger           #+#    #+#             */
/*   Updated: 2023/10/12 14:15:34 by blarger          ###   ########.fr       */
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

int	ft_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb);
}

char	*read_from_file(char *filename)
{
	int		fd;
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
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

int	ft_putstr_end(char *str, int nb)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	while (i < nb)
	{
		size--;
		i++;
	}
	while (str[size] != '\0')
	{
		write(1, &str[size], 1);
		size++;
	}
	return (0);
}

void	ft_show_file(char *input, int nb)
{
	char	*output;

	output = read_from_file((basename(input)));
	if (output == NULL)
	{
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
		return ;
	}
	else
		ft_putstr_end(output, nb);
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc < 3 || argv[1][0] != '-' || argv[1][1] != 'c' || ft(argv[2]) == 0)
	{
		write(1, "error", 5);
		return (0);
	}
	if (argc >= 4 && argv[1][0] == '-' && argv[1][1] == 'c')
	{
		i = 3;
		while (i < argc)
		{
			ft_show_file(argv[i], ft_atoi(argv[2]));
			i++;
		}
	}
	else if (argc == 3 && argv[1][0] == '-' && argv[1][1] == 'c')
	{
		ft_show_file(read_file_from_input(), ft_atoi(argv[2]));
	}
	else
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
}
