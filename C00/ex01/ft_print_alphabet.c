/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:30:29 by blarger           #+#    #+#             */
/*   Updated: 2023/09/22 08:35:10 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int	alphabet;

	alphabet = 97;
	while (alphabet < 123)
	{
		write(1, &alphabet, 1);
		alphabet++;
	}
}



int	main()
{
	ft_print_alphabet();
}