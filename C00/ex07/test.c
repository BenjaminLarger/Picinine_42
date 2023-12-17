#include	<unistd.h>

void	conversion(char *cadena, int nb, int *idx)
{
	while (nb > 0)
	{
		cadena[(*idx)++] = '0' + (nb % 10);
		nb /= 10;
	}
	cadena[*idx] = '\0';
}

void	inversion(char *cadena, int idx)
{
	int		i;
	char	temp;

	while (i < idx / 2)
	{
	temp = cadena[i];
		cadena[i] = cadena[idx - 1 - i];
		cadena[idx - 1 - i] = temp;
		i++;
	}
}

void	ft_putnbr(int nb)
{
	int		idx;
	int		i;
	char	cadena[12];

	idx = 0;
	i = 0;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	conversion(cadena, nb, &idx);
	inversion(cadena, idx);
	while (cadena[i])
	{
		write(1, &cadena[i++], 1);
	}
}
