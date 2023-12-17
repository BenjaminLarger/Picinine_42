/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 09:51:39 by blarger           #+#    #+#             */
/*   Updated: 2023/09/26 16:04:21 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <unistd.h>

int	ft_base_is_correct(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i <= 1)
	{
		return (0);
	}
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		ft_putnbr(nb);
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	length_base;

	length_base = ft_base_is_correct(base);
	if (length_base == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr < length_base)
	{
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_putnbr_base(nbr / length_base, base);
		ft_putchar(base[nbr % length_base]);
	}
}

/*int main()
{
    ft_putnbr_base(26, "ABCDE");
    return 0;
}*/