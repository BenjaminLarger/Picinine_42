/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalguer <msalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:46:50 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 18:07:26 by msalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*dup;
	int		length;
	int		i;

	length = 0;
	while (src[length] != '\0')
		length++;
	i = 0;
	dup = malloc(sizeof(char) * (length + 1));
	if (!dup)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	syntax_is_valid(char *buffer)
{
	while (*buffer != '\0')
	{
		while (*buffer >= '0' && *buffer <= '9')
			buffer++;
		while (*buffer == ' ')
			buffer++;
		if (*buffer != ':')
			return (0);
		buffer++;
		while (*buffer >= 32 && *buffer <= 126)
			buffer++;
		if (*buffer != '\n')
			return (0);
		while (*buffer == '\n')
			buffer++;
	}
	return (1);
}
