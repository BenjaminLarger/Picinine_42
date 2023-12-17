/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:49:38 by blarger           #+#    #+#             */
/*   Updated: 2023/10/09 19:56:37 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "definitions.h"
#define BUFFER_SIZE 1024

int	read_from_file(char *filename, char ***keys, char ***values)
{
	int		fd;
	char	*buffer;
	int		bytes_read;

	*keys = malloc(1080 * sizeof(char *));
	if (!keys)
		return (0);
	*values = malloc(1080 * sizeof(char *));
	if (!values)
		return (0);
	fd = open(filename, O_RDWR);
	if (fd < 0)
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	buffer[bytes_read] = '\0';
	while (bytes_read > 0)
	{
		if (syntax_is_valid(buffer) == 0)
			return (0);
		*keys = create_arrays_number(buffer, *keys);
		*values = create_arrays_cadena(buffer, *values);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (1);
}
