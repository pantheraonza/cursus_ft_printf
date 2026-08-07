/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:16:51 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:16:53 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_int(int n)
{
	long			nbr_long;
	unsigned long	nbr_unsigned;
	int				bytes;
	int				sign;

	nbr_long = (long)n;
	bytes = 0;
	sign = 0;
	if (nbr_long < 0)
	{
		if (ft_print_char('-') < 0)
			return (-1);
		nbr_long = -nbr_long;
		sign = 1;
	}
	nbr_unsigned = (unsigned long)nbr_long;
	bytes = ft_print_nbr(nbr_unsigned, "0123456789");
	if (bytes < 0)
		return (-1);
	return (bytes + sign);
}
