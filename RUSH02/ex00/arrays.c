/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:46:59 by blarger           #+#    #+#             */
/*   Updated: 2023/12/04 11:23:00 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*find_next_word(char *buffer)
{
	while (*buffer && (*buffer >= '0' && *buffer <= '9'))
		buffer++;
	while (*buffer && *buffer == ' ')
		buffer++;
	if (*buffer == ':')
		buffer++;
	else
		return (0);
	while (*buffer && *buffer == ' ')
		buffer++;
	if (*buffer && (*buffer >= 32 && *buffer <= 126))
		return (buffer);
	else
		return (0);
}

char	*extract_cadena(char	**buffer)
{
	char	temp[50];
	int		t;
	int		i;
	char	*res;

	t = 0;
	i = 0;
	while (**buffer >= 32 && **buffer <= 126)
	{
		temp[t++] = **buffer;
		(*buffer)++;
	}
	temp[t] = '\0';
	res = malloc(t + 1);
	if (!res)
		return (0);
	while (i <= t)
	{
		res[i] = temp[i];
		i++;
	}
	return (res);
}

char	**create_arrays_cadena(char *buffer, char **cadena)
{
	int		n;
	char	*word;

	n = 0;
	while (*buffer)
	{
		word = find_next_word(buffer);
		if (word)
		{
			buffer = word;
			cadena[n++] = extract_cadena(&buffer);
		}
		else
			buffer++; 
	}
	cadena[n] = NULL;
	return (cadena);
}

char	*extract_number(char **buffer)
{
	char	temp[50];
	int		t;
	int		i;
	char	*res;

	t = 0;
	i = 0;
	while (**buffer >= '0' && **buffer <= '9')
	{
		temp[t++] = **buffer;
		(*buffer)++;
	}
	temp[t] = '\0';
	res = malloc(t + 1);
	while (i <= t)
	{
		res[i] = temp[i];
		i++;
	}
	return (res);
}

char	**create_arrays_number(char *buffer, char **number)
{
	int		n;

	n = 0;
	while (*buffer)
	{
		if (*buffer >= '0' && *buffer <= '9')
			number[n++] = extract_number(&buffer);
		else
			buffer++;
		if (*buffer == ':')
		{
			while (*buffer != '\n')
				buffer++;
		}
		buffer++;
	}
	number[n] = NULL;
	return (number);
}
