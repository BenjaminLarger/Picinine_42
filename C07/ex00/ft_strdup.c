/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:17:02 by blarger           #+#    #+#             */
/*   Updated: 2023/09/30 08:38:20 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

/*int main()
{
	char str[] = "string";
	char *dup;
	dup = ft_strdup(str);
	printf("%s", dup);
}*/