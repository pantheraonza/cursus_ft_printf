/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_b2_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 17:23:14 by criredon          #+#    #+#             */
/*   Updated: 2026/08/06 17:23:15 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	emulated;
	int	original;

	emulated = ft_printf("Cadena: %s!\n", "42");
	original = printf("Cadena: %s!\n", "42");
	printf("Test 0 -> original=%d emulated=%d\n", original, emulated);
	ft_printf("Test 0 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("Nulo: %s\n", (char *) NULL);
	original = printf("Nulo: %s\n", (char *) NULL);
	printf("Test 1 -> original=%d emulated=%d\n", original, emulated);
	ft_printf("Test 1 -> original=%d emulated=%d\n", original, emulated);
	return (0);
}
