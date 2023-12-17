/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 10:05:37 by blarger           #+#    #+#             */
/*   Updated: 2023/10/02 15:37:17 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	prime;

	prime = 2;
	if (nb < 2)
		return (0);
	while (prime <= (nb / 2))
	{
		if (!(nb % prime))
			return (0);
		else
			prime++;
	}
	return (1);
}

/*int	main(void)
{
	int	i;

	for (i = 2; i <= 20; i++)
	{
		if (ft_is_prime(i))
			printf("%d est un nombre premier.\n", i);
		else
			printf(" ");
	}
	return (0);
}*/