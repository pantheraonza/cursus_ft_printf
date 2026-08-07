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

int	ft_print_nbr(long n)
{
	int		bytes;
	long	number;

	bytes = 0;
	number = n;
	if (number < 0)
	{
		bytes = bytes + ft_print_char('-');
		number = -number;
	}
	if (number >= 10)
		bytes += ft_print_nbr(number / 10);
	bytes += ft_print_char((number % 10) + '0');
	return (bytes);
}
{
	long	number;

	if (fd < 0)
		return ;
	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number = -number;
	}
	if (number >= 10)
		ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd((number % 10) + '0', fd);
}
