/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 08:22:37 by blarger           #+#    #+#             */
/*   Updated: 2023/10/02 08:13:32 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_char(char c)
{
	if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
	{
		return (0);
	}
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	start;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_char(str[i]) == 1)
			start = 1;
		if (start == 1 && (ft_char(str[i]) == 1))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] - 32;
			start = 0;
			i++;
		}
		while (ft_char(str[i]) == 1 || (str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
				str[i] = str[i] + 32;
			i++;
		}
		start = 0;
		i++;
	}
	return (str);
}

// int	main(void)
//{
//   char test1[] = "hello, world!";
//   char test2[] = "salut, comment tu vas ? 
//42mots quarante-deux; cinquante+et+un";
//    char test3[] = "1a 2b 3c";
//    char test4[] = "HELLO";
//    char test5[] = "aBCD";

//   printf("Test 1: %s\n", ft_strcapitalize(test1));
//   printf("Test 2: %s\n", ft_strcapitalize(test2));
// printf("Test 3: %s\n", ft_strcapitalize(test3));
//  printf("Test 4: %s\n", ft_strcapitalize(test4));
//  printf("Test 5: %s\n", ft_strcapitalize(test5));

//  return (0);
//}
