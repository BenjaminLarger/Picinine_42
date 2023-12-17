/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:47:58 by blarger           #+#    #+#             */
/*   Updated: 2023/10/09 20:31:49 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <stdio.h>

char	*get_numbers_left_aux(char *input, int length, int i)
{
	char	*result;

	// input = 123456 => 123450
	if (i > 0)
	{
		result = copy_array(input, 0, length);
		result[i] = '0';
		return (result);
	}
	// input = 500.000 => 100.000
	else if (i == 0 && input[length - 1] == '0' && input[0] != '1')
	{
		result = copy_array(input, 0, length);
		result[0] = '1';
		return (result);
	}
	return (NULL);
}

/**
 * get_number_left("123.456", 6) => "123.450"
 * get_number_left("123.450", 6) => "123.400"
 * get_number_left("123.400", 6) => "123.000"
 * get_number_left("200.000", 6) => "100.000"
 * get_number_left("10.000", 6) => "1.000"
*/
char	*get_number_left(char *input, int *length)
{
	int	i;

	i = *length - 1;
	// recorro los zeros por el final
	while (i > 0 && input[i] == '0')
	{
		i--;
	}
	
	// elimino un zero por la derecha
	// input = "100,000"
	if (i == 0 && input[*length - 1] == '0' && input[0] == '1')
	{
		*length = *length - 1;
		return (copy_array(input, 0, *length));
	}
	else
	{
		return (get_numbers_left_aux(input, *length, i));
	}
	return (NULL);
}

/**
 * crearme la mascara
 * get_mask_index("100.000") => (el indice en el array de las keys del diccionario) => "1000"  
*/
int	get_mask_index(char *input, char **keys, int length)
{
	int		i;
	char	*left;

	i = get_index_in_dictionary(input, keys);
	if (i >= 0)
	{
		return (i);
	}
	else if (length == 0)
	{
		return (-1);
	}
	left = get_number_left(input, &length);
	if (left == NULL)
	{
		return (-1);
	}
	return (get_mask_index(left, keys, length));
}

/**
 * El mask es "1000" y su length es 4
 * apply_left_mask("123456", 6, 4) => "123"
 * apply_left_mask("200", 3, 3) =>  "2"
 * apply_left_mask("23", 2, 2) => null -> voy a aplicar la mascara de la derecha
*/
char	*apply_left_mask(char *input, int length_input, int length_mask)
{
	if (length_input == length_mask)
	{
		if (length_mask <= 2)
		{
			return (NULL);
		}
		return (copy_array(input, 0, 1));
	}
	return (copy_array(input, 0, length_input - length_mask + 1));
}

/**
 * apply_right_mask("123 456", "1000", 6, 4) => "456"
 * apply_right_mask("23", "20", 2, 2) => "3"
 * apply_right_mask("20", "20", 2, 2) => "0"
 * apply_right_mask("500", "100", 3, 3) => "00" => null
*/
char	*apply_right_mask(char *input, char *mask, int length_input,
		int length_mask)
{
	int	i;

	i = 0;
	while (i < length_mask && mask[length_mask - i - 1] == '0')
	{
		i++;
	}
	return (copy_array(input, length_input - i, i));
}
