/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 06:10:15 by blarger           #+#    #+#             */
/*   Updated: 2023/10/04 14:34:27 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ABS_H
# define FT_ABS_H

# define ABS(Value) (Value < 0 ? -Value : Value)

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

#endif