/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:57:47 by blarger           #+#    #+#             */
/*   Updated: 2023/09/24 13:44:58 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
		{
			if (!(str[i] >= 'A' && str[i] <= 'Z'))
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

/*int main()
{
    char src[] = "salut";
	int result = ft_str_is_alpha(src);
	printf("%d\n", result);
}*/
