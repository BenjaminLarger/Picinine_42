/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_constraint_left_right.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:12:08 by blarger           #+#    #+#             */
/*   Updated: 2023/10/01 15:27:57 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	view_constraint_left_right(int y, int mat[4][4], int rs)
{
	int	x;
	int	count;
	int	previous_tallest;

	x = 1;
	count = 1;
	previous_tallest = mat[3][y];
	while (x >= 0)
	{
		if (mat[x][y] > previous_tallest)
		{
			count++;
			previous_tallest = mat[x][y];
		}
		x--;
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
	int	y;

	fill_matrix(mat);
	rs = 2;
	y = 2;
	result = view_constraint_left_right(y, mat, rs);
	if (result == 1)
		write(1, "The constraint is respected for the row", 39);
	else
		write(1, "The constraint isn't respected for the row", 42);
	return (0);
}
