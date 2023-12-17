/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 12:58:08 by blarger           #+#    #+#             */
/*   Updated: 2023/09/26 17:24:23 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;

	i = 0;
	size = size - 1;
	while (i < size)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
		i++;
		size--;
	}
}

/*int main()
{
    int tab1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    int tab2[] = {1, 2};
    int size2 = 2;
    int tab3[] = {1};
    int size3 = 1;

    ft_rev_int_tab(tab1, size1);
    ft_rev_int_tab(tab2, size2);
    ft_rev_int_tab(tab3, size3);

    for (int i = 0; i < size1; i++)
        printf("%d ", tab1[i]);
    printf("\n");

    for (int i = 0; i < size2; i++)
        printf("%d ", tab2[i]);
    printf("\n");

    for (int i = 0; i < size3; i++)
        printf("%d ", tab3[i]);
    printf("\n");

    return 0;
}
*/