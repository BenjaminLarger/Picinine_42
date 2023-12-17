/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:07:41 by blarger           #+#    #+#             */
/*   Updated: 2023/09/25 12:43:42 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

char	*ft_strcat2(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0' && (i + j) < size - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	if (i < size)
	{
		dest[i] = '\0';
	}
	return (dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	length_src;
	unsigned int	length_dest;

	length_dest = 0;
	while (dest[length_dest])
	{
		length_dest++;
	}
	length_src = 0;
	while (src[length_src])
	{
		length_src++;
	}
	if (size <= length_dest)
	{
		return (size + length_src);
	}
	ft_strcat2(dest, src, size);
	return (length_dest + length_src);
}
