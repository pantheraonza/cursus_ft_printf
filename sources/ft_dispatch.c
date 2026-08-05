/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:06:07 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:06:09 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_dispatch(char conv_type, va_list args)
{
    if (conv_type == 'c')
        return (ft_print_char(va_arg(args, int)));
    // if (conv_type == '%')
    //     return (ft_print_char('%');
    return (ft_print_char('%'));
}

