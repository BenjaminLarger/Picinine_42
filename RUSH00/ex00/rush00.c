void	print_encima(int x)
{
	int	i;

	ft_putchar('o');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('-');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('o');
	}
	ft_putchar('\n');
}

void	print_medio(int x)
{
	int	i;

	ft_putchar('|');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar(' ');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('|');
	}
	ft_putchar('\n');
}

void	print_abajo(int x)
{
	int	i;

	ft_putchar('o');
	i = 1;
	while (i < x - 1)
	{
		ft_putchar('-');
		i++;
	}
	if (x > 1)
	{
		ft_putchar('o');
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
