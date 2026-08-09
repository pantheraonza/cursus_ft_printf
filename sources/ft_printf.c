/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:05:50 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:05:53 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_scan(char const *format, va_list args)
{
	size_t		i;
	int			total_bytes;
	int			partial_bytes;

	i = 0;
	total_bytes = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			partial_bytes = ft_dispatch(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			partial_bytes = ft_print_char(format[i]);
			i = i + 1;
		}
		total_bytes = total_bytes + partial_bytes;
	}
	return (total_bytes);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			total_bytes;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	total_bytes = ft_scan(format, args);
	va_end(args);
	return (total_bytes);
}
