/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 07:16:17 by blarger           #+#    #+#             */
/*   Updated: 2023/10/04 15:39:43 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

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

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*str;

	i = 0;
	str = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!str)
		return (0);
	while (i < ac)
	{
		str[i].size = ft_strlen(av[i]);
		str[i].str = av[i];
		str[i].copy = ft_strdup(av[i]);
		i++;
	}
	str[i].str = 0;
	str[i].copy = 0;
	return (str);
}

 #include <stdio.h>

int main(void)
{
    char *agv[] = {"Aller", "Ciao", "!", "Testing", "vale"};
    int acc = 5;
    t_stock_str *arr = ft_strs_to_tab(acc, agv);

    for (int i = 0; i < acc; i++)
    {
        printf("Original: %s, Copy: %s\n", arr[i].str, arr[i].copy);
    }

    // Si vous avez écrit une fonction pour libérer la mémoire, appelez-la ici.
    // liberta(arr);

    return 0;
}
