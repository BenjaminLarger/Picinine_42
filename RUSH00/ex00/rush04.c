/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:05:18 by blarger           #+#    #+#             */
/*   Updated: 2023/09/24 19:05:22 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_encima(int x)
{
	int	i;

	ft_putchar('A');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('C');
	}
	ft_putchar('\n');
}

void	print_medio(int x)
{
	int	i;

	ft_putchar('B');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar(' ');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('B');
	}
	ft_putchar('\n');
}

void	print_abajo(int x)
{
	int	i;

	ft_putchar('C');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('B');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('A');
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	if (x <= 0 || y <= 0)
	{
		write(1, "Escribe un entero superior a 0", 30);
		return ;
	}
	print_encima(x);
	j = 1;
	while (j < y - 1)
	{
		print_medio(x);
		j++;
	}
	if (y > 1)
	{
		print_abajo(x);
	}
}