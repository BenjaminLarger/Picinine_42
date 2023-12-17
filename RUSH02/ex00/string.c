/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalguer <msalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:56:16 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 20:47:56 by msalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*copy_array(char *input, int start, int length)
{
	char	*result;
	int		i;
	int		end;

	result = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	end = start + length;
	while (i < end)
	{
		result[i] = input[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*delete_left_zeros(char *input)
{
	while (*input && *input == '0')
	{
		input++;
	}
	if (!*input)
	{
		return (NULL);
	}
	return (input);
}

void	free_list_string(char **list_string)
{
	int	i;

	i = 0;
	while (list_string[i] != NULL)
	{
		free(list_string[i]);
		i++;
	}
	free(list_string);
	list_string = NULL;
}

int	ft_length(char *str)
{
	int	i;

	if (str == NULL)
	{
		return (0);
	}
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] < s2[i])
			return (-1);
		if (s1[i] > s2[i])
			return (1);
		i++;
	}
	return (0);
}
