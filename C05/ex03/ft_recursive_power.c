/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:06:24 by blarger           #+#    #+#             */
/*   Updated: 2023/09/27 12:03:35 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	nb_copy;

	nb_copy = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return (nb_copy * ft_recursive_power(nb, power - 1));
}

/*int main()
{
	int result = ft_recursive_power(-6,0);
	printf("%d", result);
}*/