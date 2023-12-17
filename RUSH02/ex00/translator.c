/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:54:19 by blarger           #+#    #+#             */
/*   Updated: 2023/10/09 20:37:54 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>

char	*get_separator(int mask_length)
{
	// 23 => twenty-three
	if (mask_length == 2)
	{
		return ("-");
	}
	// 123 => "one hundred" and "twenty-three"
	if (mask_length == 3)
	{
		return (" and ");
	}
	// 1234 => (one thousand), (2 hundred and thirty-four)
	if (mask_length > 3)
	{
		return (", ");
	}
	// 6.000.200 => 6 million two hundred
	return (" ");
}

/**
 * translate(500) =>
 * 		left: 5 - five 
 * 		mask: 100 - hundred
 * 		right: 00 (null)
 *
 * translate(5123) =>
 * 		left: 5 - five 
 * 		mask: 1000 - thousand
 * 		right: 123 - 
 * 
 * translate(5000) =>
 * 		left: 5 - five 
 * 		mask: 1000 - thousand
 * 		right: 000 - null
*/
void	translate_by_parts(char *input, int input_length, char **keys,
		char **values)
{
	int		mask_index;
	char	*right;
	char	*left;
	int		mask_key_length;

	mask_index = get_mask_index("123456", keys, input_length); // => 1000
	mask_key_length = ft_length(keys[mask_index]); // 4
	left = apply_left_mask(input, input_length, mask_key_length);  // left = "123"
	if (left)
	{
		translate(left, keys, values);  // traducir (123) => one hundred twenty-three
		show_message(" "); // "one hundred twenty-three "
	}
	show_message(values[mask_index]);  // one hundred twenty-three thousand
	right = delete_left_zeros(apply_right_mask(input, keys[mask_index],
				input_length, mask_key_length));  // 654
	if (right != NULL)
	{
		show_message(get_separator(mask_key_length)); // ", "
		translate(right, keys, values);  // six-hundred fifty-four
	}
}

/**
 * Dado el input que nos da el usuario y los valores del diccionario
 * tenemos que pintar por linea de comandos su valor
 *
 * Devolvemos 0 si no podemos "traducir" el número. Esto puede pasar
 * si el diccionario no contiene traducción para algunos números.
 *
 * 123,000,000 =>
 * */
void	translate(char *input, char **keys, char **values)
{
	int	input_length;
	int	mask_index;

	input_length = ft_length(input);
	mask_index = get_index_in_dictionary(input, keys);
	if (mask_index >= 0)
	{
		show_message(values[mask_index]);
		return ;
	}
	if (input_length == 0)
	{
		return ;
	}
	translate_by_parts(input, input_length, keys, values);
}
