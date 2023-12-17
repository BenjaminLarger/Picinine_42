/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 09:26:04 by blarger           #+#    #+#             */
/*   Updated: 2023/10/05 08:18:46 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_concatenation(int size, char *sep, char **strs, char *tab)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = 0;
	while (i < size)
	{
		len = ft_strlen(strs[i]);
		ft_strcpy(&tab[j], strs[i]);
		j = j + len;
		if (i < size - 1)
		{
			len = ft_strlen(sep);
			ft_strcpy(&tab[j], sep);
			j += len;
		}
		i++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{	
	char	*tab;
	int		length;

	if (size == 0)
		return (0);
	length = ft_strlen(sep);
	tab = malloc((length + 1) * sizeof(char));
	ft_concatenation(size, sep, strs, tab);
	return (tab);
}

/* int main(void)
{
    char *str1 = "Hello";
    char *str2 = "world";
    char *str3 = "from";
    char *str4 = "Malaga";
    char *separator = ", ahah ,";

    char *strs[4] = {str1, str2, str3, str4};

    char *result = ft_strjoin(4, strs, separator);

    if (result)
    {
        printf("%s\n", result);
        free(result); // N'oubliez pas de libérer la mémoire allouée
    }
    else
    {
        printf("Error: ft_strjoin returned NULL.\n");
    }

    return 0;
}
 */