/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:03:45 by blarger           #+#    #+#             */
/*   Updated: 2023/09/26 15:54:36 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <unistd.h>

int	ft_base_is_correct(int *i, char *base)
{
	int	j;

	while (base[*i] != '\0')
	{
		j = (*i) + 1;
		if (base[*i] == '+' || base[*i] == '-')
			return (0);
		if (base[*i] == ' ')
			return (0);
		while (base[j] != '\0')
		{
			if (base[*i] == base[j])
				return (0);
			j++;
		}
		(*i)++;
	}
	if (*i <= 1)
	{
		return (0);
	}
	return (*i);
}

int	ft_whitespace(int *i, char *str)
{
	while (str[*i] != '\0')
	{
		if (str[*i] == ' ' || str[*i] == '\t')
		{	
			(*i)++;
		}
		else if (str[*i] == '\n' || str[*i] == '\v')
		{
			(*i)++;
		}
		else if (str[*i] == '\f' || str[*i] == '\r')
		{
			(*i)++;
		}
		else
		{
			break ;
		}
	}
	return (*i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	signo;

	i = 0;
	nb = 0;
	ft_whitespace(&i, str);
	signo = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = signo * -1;
		(i)++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (signo == -1)
		nb = -nb;
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	length_base;
	int	nbr;

	ft_base_is_correct(&length_base, base);
	nbr = ft_atoi(str);
	if (length_base == 0)
		return (0);
	else if (nbr < length_base)
	{
		ft_putchar(base[nbr]);
	}
	else
	{
		ft_atoi_base(nbr / length_base, base);
		ft_putchar(base[nbr % length_base]);
	}
	return (nbr);
}
/*int main(void)
{
    ft_atoi_base(26, "ABCDE");
    return 0;
}
*/