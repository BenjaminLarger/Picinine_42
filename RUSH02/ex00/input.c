/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:52:35 by blarger           #+#    #+#             */
/*   Updated: 2023/10/09 10:41:39 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	clean_input_user(char *input)
{
	int	i;
	int	isclean;

	i = 0;
	isclean = 1;
	while (input[i] != '\0')
	{
		if (is_space(input[i]))
			i++;
		else if (input[i] < '0' || input[i] > '9')
		{
			isclean = 0;
		}
		i++;
	}
	if (i > 40)
	{
		isclean = 0;
	}
	return (isclean);
}

char	*get_number_without_zeros(char *input)
{
	while (*input != '\0' && is_space(*input))
		input++;
	while (*input != '\0' && *input == '0')
		input++;
	if (input == NULL || *input == '\0')
	{
		input--;
	}
	return (input);
}

/**
 * No tenemos que cambiar esta funcion
 */
char	*read_number_from_input(void)
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
