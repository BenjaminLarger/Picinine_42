/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 14:08:25 by blarger           #+#    #+#             */
/*   Updated: 2023/10/12 14:11:16 by blarger          ###   ########.fr       */
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

char	*read_file_from_input(char *buffer)
{
	int		bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, sizeof(char) * 1080);
	if (bytes_read < 0)
	{
		return (0);
	}
	buffer[bytes_read - 1] = '\0';
	return (buffer);
}
