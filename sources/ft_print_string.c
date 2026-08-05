/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:17:27 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:17:28 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int ft_print_string(char *str)
{
    int bytes;

    if (str == NULL)
        return (write(1, "(null)", 6));
    bytes = write(1, str, ft_strlen(str));
    return (bytes);
}

int main(void)
{
    char    str;

    str = "Hello World";
    ft_print_string(str);
    // ft_print_char('\n');
    return (0);
}
