/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:35:36 by blarger           #+#    #+#             */
/*   Updated: 2023/09/24 13:47:25 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
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