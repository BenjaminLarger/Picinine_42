/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalguer <msalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:56:16 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 21:21:19 by msalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#define FILENAME_DEFAULT "dictionaries/numbers.dict"

int	main_when_number_and_filename(char *number, char *filename)
{
	int		ok;
	char	**dict_keys;
	char	**dict_values;

	ok = clean_input_user(number);
	if (!ok)
	{
		show_message("Error\n");
		return (1);
	}
	number = get_number_without_zeros(number);
	ok = read_from_file(filename, &dict_keys, &dict_values);
	if (!ok)
	{
		show_message("Dict Error\n");
		return (1);
	}
	translate(number, dict_keys, dict_values);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		return (main_when_number_and_filename(read_number_from_input(),
				FILENAME_DEFAULT));
	}
	if (argc == 2)
	{
		return (main_when_number_and_filename(argv[1], FILENAME_DEFAULT));
	}
	if (argc == 3)
	{
		return (main_when_number_and_filename(argv[2], argv[1]));
	}
	show_message("Error\n");
	return (1);
}
