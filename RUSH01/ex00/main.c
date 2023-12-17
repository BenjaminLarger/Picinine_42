/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:11:43 by blarger           #+#    #+#             */
/*   Updated: 2023/10/04 16:25:38 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_sep(int res[16])
{
	int	colup[4];
	int	coldown[4];
	int	rowleft[4];
	int	rowright[4];
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			colup[i] = res[i];
		else if (i < 8)
			coldown[i - 4] = res[i];
		else if (i < 12)
			rowleft[i - 8] = res[i];
		else if (i < 16)
			rowright[i - 12] = res[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	restric[16];
	int	count;

	i = 0;
	count = 0;
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (1);
	}
	while (argv[1][i] && count < 16)
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
		{
			restric[count] = argv[1][i] - '0';
			count++;
		}
		i++;
	}
	ft_sep(restric);
	return (0);
}
