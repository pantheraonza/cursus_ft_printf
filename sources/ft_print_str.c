/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:17:27 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:17:28 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int ft_print_str(char *str)
{
    int bytes;

    if (str == NULL)
        return (write(1, "(null)", 6));
    bytes = write(1, str, ft_strlen(str));
    return (bytes);
}
