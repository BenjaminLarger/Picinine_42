/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:16:05 by blarger           #+#    #+#             */
/*   Updated: 2023/10/09 08:41:05 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#define BUFFER_SIZE 1024

void	ft_write_buffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		write(1, &buffer[i], 1);
		i++;
	}
}

int	read_from_file(char *filename)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	fd = open(filename, O_RDWR);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	while (bytes_read > 0)
	{
		ft_write_buffer(buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	ouvre;

	if (argc < 2)
	{
		write(1, "File name missing\n", 18);
		return (-1);
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments\n", 18);
		return (-1);
	}
	else
	{
		ouvre = open(argv[1], O_RDONLY);
		if (ouvre == -1)
			return (-1);
		read_from_file(argv[1]);
	}
}
