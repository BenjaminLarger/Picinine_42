/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:08:09 by blarger           #+#    #+#             */
/*   Updated: 2023/09/28 13:20:16 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

/*int main()
{
	int result = 0;
	result = ft_recursive_factorial(5);
	printf("%d", result);
}*/