/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 08:27:37 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 11:59:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			k = i;
			while (str[k] == to_find[j] && to_find[j] != '\0')
			{
				k++;
				j++;
			}
			if (to_find[j] == '\0' && str[i] != '\0')
				count++;
		}
		i++;
	}
	return (count);
}

char	*ft_strdup(char *src, int start, int end)
{
	char	*dup;
	int		i;

	if (end <= start)
		return (0);
	i = 0;
	dup = malloc(sizeof(char) * (end - start + 1));
	if (!dup)
		return (0);
	while (start < end)
	{
		dup[i] = src[start];
		i++;
		start++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strstr2(char *str, char *to_find, int i)
{
	int	j;
	int	k;

	if (!*to_find)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			k = i;
			while (str[k] == to_find[j] && to_find[j] != '\0')
			{
				k++;
				j++;
			}
			if (to_find[j] == '\0' && str[i] != '\0')
				return (i);
		}
		i++;
	}
	return (-1);
}

char	**ft_split(char *str, char *charset)
{
	int		tab_count;
	int		j;
	int		str_count;
	int		len;
	char	**tab;

	tab_count = 0;
	j = 0;
	str_count = 0;
	len = ft_strstr(str, charset) + 1;
	tab = malloc((len + 1) * sizeof(char *));
	while (str[str_count] && tab_count < len)
	{
		j = ft_strstr2(str, charset, str_count);
		if (j == -1)
			j = ft_strlen(str);
		tab[tab_count] = ft_strdup(str, str_count, j);
		if (!tab[tab_count])
			return (0);
		str_count = j + ft_strlen(charset);
		tab_count++;
	}
	tab[len] = 0;
	return (tab);
}

/* int main(void)
{
    char **result;
    int i, j;
    char *tests[][2] = {
        {"Salut comment vas-tu ?", "z"},
        {"", "-"},
        {"Salut comment vas-tu ?", ""},
        {"Salut---comment vas-tu ?", "---"},
        {"Salut comment vas-tu ?-Bien, merci. Et toi ?", "-"}
    };

    for (j = 0; j < 5; j++)
    {
        printf("Test %d:\n", j + 1);
        result = ft_split(tests[j][0], tests[j][1]);
        
        if (result == NULL) {
            printf("Error: ft_split returned NULL\n");
            continue;
        }

        i = 0;
        while (result[i])
        {
            printf("Segment %d : %s\n", i, result[i]);
            i++;
        }
        printf("\n");
    }

    return (0);
} */
