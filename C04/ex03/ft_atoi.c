/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:08:07 by blarger           #+#    #+#             */
/*   Updated: 2023/09/26 16:01:34 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

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

int	ft_signo(int *i, char *str)
{
	int	signo;

	signo = 1;
	while (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			signo = signo * -1;
		}
		(*i)++;
	}
	return (signo);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	signo;

	i = 0;
	nb = 0;
	ft_whitespace(&i, str);
	signo = ft_signo(&i, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	if (signo == -1)
	{
		nb = -nb;
	}
	return (nb);
}

/*int main()
{
	char str[] = "---+--+1234ab567";
	int result = ft_atoi(str);
	printf("%d", result);
}*/
