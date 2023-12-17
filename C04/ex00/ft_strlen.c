/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:55:51 by blarger           #+#    #+#             */
/*   Updated: 2023/09/26 16:02:05 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' )
	{
		i++;
	}
	return (i);
}

/*int main()
{
	char str[] = "hello";
	int result = ft_strlen(str);
	printf("length = %d\n", result);
}*/
