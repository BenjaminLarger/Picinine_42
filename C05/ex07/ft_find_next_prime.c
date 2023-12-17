/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:37:12 by blarger           #+#    #+#             */
/*   Updated: 2023/10/02 15:37:46 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_find_next_prime(int nb)
{
	int	prime;

	prime = 2;
	if (nb <= 2)
		return (2);
	while (prime * prime <= nb)
	{
		while (nb % prime != 0)
		{
			prime++;
		}
		if (nb == prime)
			return (nb);
		prime = 2;
		nb++;
		while (nb % 2 == 0 || nb % 3 == 0)
			nb++;
	}
	return (nb);
}

/*int	main(void)
{
	int	i;
	int result;

	for (i = 10; i <= 20; i++)
	{
		result = ft_find_next_prime(i);
		printf("avec %d, %d est le prochain nombre premier.\n", i, result);
	}
	return (0);
}*/