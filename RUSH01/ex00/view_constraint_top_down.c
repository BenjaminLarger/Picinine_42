/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_constraint_top_down.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:12:21 by blarger           #+#    #+#             */
/*   Updated: 2023/10/01 15:30:48 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	view_constraint_top_down(int x, int mat[4][4], int rs)
{
	int	y;
	int	count;
	int	previous_tallest;

	y = 1;
	count = 1;
	previous_tallest = mat[x][0];
	while (y < 4)
	{
		if (mat[x][y] > previous_tallest)
		{
			count++;
			previous_tallest = mat[x][y];
		}
		y++;
	}
	if (count == rs)
		return (1);
	else
		return (-1);
}

void	fill_matrix(int matrice[4][4])
{
	matrice[0][0] = 1;
	matrice[0][1] = 2;
	matrice[0][2] = 3;
	matrice[0][3] = 4;
	matrice[1][0] = 2;
	matrice[1][1] = 3;
	matrice[1][2] = 4;
	matrice[1][3] = 1;
	matrice[2][0] = 3;
	matrice[2][1] = 4;
	matrice[2][2] = 1;
	matrice[2][3] = 2;
	matrice[3][0] = 4;
	matrice[3][1] = 1;
	matrice[3][2] = 2;
	matrice[3][3] = 3;
}

int	main(void)
{
	int	mat[4][4];
	int	result;
	int	rs;
	int	x;

	fill_matrix(mat);
	rs = 2;
	x = 2;
	result = view_constraint_top_down(x, mat, rs);
	if (result == 1)
		write(1, "The constraint is respected for the column", 42);
	else
		write(1, "The constraint isn't respected for the column", 45);
	return (0);
}
