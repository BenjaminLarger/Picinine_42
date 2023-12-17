/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:30:54 by blarger           #+#    #+#             */
/*   Updated: 2023/09/22 08:38:44 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int	alphabet;

	alphabet = 122;
	while (alphabet >= 97)
	{
		write(1, &alphabet, 1);
		alphabet--;
	}
}

int	main()
{
	ft_print_reverse_alphabet();
}
