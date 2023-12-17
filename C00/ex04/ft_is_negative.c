/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:31:35 by blarger           #+#    #+#             */
/*   Updated: 2023/09/22 08:43:54 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	positive;
	char	negative;

	positive = 'P';
	negative = 'N';
	if (n >= 0)
	{
		write(1, &positive, 1);
	}
	if (n < 0)
	{
		write(1, &negative, 1);
	}
}

int	main()
{
	ft_is_negative(-5);
	ft_is_negative(5);
	ft_is_negative(0);
}