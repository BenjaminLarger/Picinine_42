/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:36:48 by blarger           #+#    #+#             */
/*   Updated: 2023/09/27 12:20:54 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = nb - 1;
	while (i != 0)
	{
		nb = nb * i;
		i--;
	}
	return (nb);
}

/*int main()
{
	int result;
	result = ft_iterative_factorial(0);
	printf("%d", result);
}*/