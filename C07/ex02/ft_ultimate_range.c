/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 08:56:59 by blarger           #+#    #+#             */
/*   Updated: 2023/10/02 18:57:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc((max - min) * sizeof(int));
	i = 0;
	while ((min + i) < max)
	{
		tab[i] = min + i;
		i++;
	}
	*range = tab;
	return (max - min);
}

/*int main(void)
{
    int ptr = 5;
	int *range = &ptr;
	int size = ft_ultimate_range(&range, 5, 10);
	int i;

	if (size == -1)
	{
		printf("Erreur d'allocation mémoire.\n");
		return (1);
	}

	for (i = 0; i < size; i++)
	{
		printf("%d ", range[i]);
	}
	printf("\n");

	free(range);  // Ne pas oublier de libérer la mémoire !
	return (0);
}*/
