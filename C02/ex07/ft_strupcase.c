/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:30:45 by blarger           #+#    #+#             */
/*   Updated: 2023/09/24 11:43:01 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
	i++;
	}
	return (str);
}

/*int main()
{
    char test1[] = "hello";
    char test2[] = "WORLD";
    char test3[] = "MiXeD CaSe";
    char test4[] = "";

    printf("(original: hello): %s\n", ft_strupcase(test1));
    printf("(original: WORLD): %s\n", ft_strupcase(test2));
    printf("(original: MiXeD CaSe): %s\n", ft_strupcase(test3));
    printf("(original: <>): %s\n", ft_strupcase(test4));

    return 0;
}*/