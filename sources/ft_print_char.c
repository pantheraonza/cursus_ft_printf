/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:16:27 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:16:29 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_char(char c)
{
	int		bytes;

	bytes = write(1, &c, 1);
	return (bytes);
}

// int main(void)
// {
//     ft_print_char('A');
//     ft_print_char('\n');
//     return (0);
// } 