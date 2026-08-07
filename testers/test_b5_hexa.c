/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_b5_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:58:16 by criredon          #+#    #+#             */
/*   Updated: 2026/08/07 18:58:17 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	emulated;
	int	original;

	emulated = ft_printf("min: %x\n", 255);
	original = printf("min: %x\n", 255);
	ft_printf("Test 0 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("MAX: %X\n", 255);
	original = printf("MAX: %X\n", 255);
	ft_printf("Test 1 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("neg: %x\n", -1);
	original = printf("neg: %x\n", -1);
	ft_printf("Test 2 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("imin: %x\n", INT_MIN);
	original = printf("imin: %x\n", INT_MIN);
	ft_printf("Test 3 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("MAX: %X\n", UINT_MAX);
	original = printf("MAX: %X\n", UINT_MAX);
	ft_printf("Test 4 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("zero: %x\n", 0);
	original = printf("zero: %x\n", 0);
	ft_printf("Test 5 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("letters: %x\n", 3735928559U);
	original = printf("letters: %x\n", 3735928559U);
	ft_printf("Test 6 -> original=%d emulated=%d\n", original, emulated);
	return (0);
}
