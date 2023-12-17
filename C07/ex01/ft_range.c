/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:24:44 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 12:12:51 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
		return (0);
	tab = malloc((max - min) * sizeof(int));
	i = 0;
	while ((min + i) < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}

int main(void)
{
	int *result;
	int min = -3;
	int max = 10;
	int i = 0;

	result = ft_range(min, max);
	while (i < max - min)
	{
		printf("%d ", result[i]);
		i++;
	}
	printf("\n");
	return (0);
}