/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 08:25:18 by blarger           #+#    #+#             */
/*   Updated: 2023/10/02 15:34:45 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	sqrt;
	int	j;

	sqrt = 3;
	j = nb / 3;
	if (nb == 1)
		return (1);
	else if (nb == 4)
		return (2);
	while (!(sqrt > j))
	{
		if (sqrt * sqrt == nb)
		{
			return (sqrt);
		}
		else if (sqrt >= 46341)
			return (0);
		sqrt++;
	}
	return (0);
}

/*int main()
{
	int result = ft_sqrt(9);
	printf("%d", result);
}*/