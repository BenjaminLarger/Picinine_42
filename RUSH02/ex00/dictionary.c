/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalguer <msalguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:47:58 by blarger           #+#    #+#             */
/*   Updated: 2023/10/08 20:53:52 by msalguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "definitions.h"
#include <stdlib.h>

int	get_index_in_dictionary(char *key_dict, char **keys)
{
	int	i;

	i = 0;
	while (keys[i] != NULL && ft_strcmp(key_dict, keys[i]) != 0)
	{
		i++;
	}
	if (keys[i] != NULL && ft_strcmp(key_dict, keys[i]) == 0)
	{
		return (i);
	}
	return (-1);
}
