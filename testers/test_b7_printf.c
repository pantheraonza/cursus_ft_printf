/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_b7_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 16:06:39 by criredon          #+#    #+#             */
/*   Updated: 2026/08/09 16:06:41 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "../include/ft_printf.h"

int	main(void)
{
	int	emulated;
	int	original;
	int	x;

	x = 42;
	emulated = ft_printf("Todo: c=%c s=%s d=%d u=%u x=%x X=%X p=%p pct=%%\n",
			'A', "hola", -42, 42, 255, 255, &x);
	original = printf("Todo: c=%c s=%s d=%d u=%u x=%x X=%X p=%p pct=%%\n",
			'A', "hola", -42, 42, 255, 255, &x);
	ft_printf("Test 0 (mezcla) -> original=%d emulated=%d\n\n", original, emulated);
	emulated = ft_printf("dmin=%d dmax=%d imin=%i\n", INT_MIN, INT_MAX, INT_MIN);
	original = printf("dmin=%d dmax=%d imin=%i\n", INT_MIN, INT_MAX, INT_MIN);
	ft_printf("Test 1 (bordes int) -> original=%d emulated=%d\n\n", original, emulated);
	emulated = ft_printf("umax=%u xmax=%x Xmax=%X\n", UINT_MAX, UINT_MAX, UINT_MAX);
	original = printf("umax=%u xmax=%x Xmax=%X\n", UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("Test 2 (bordes unsigned) -> original=%d emulated=%d\n\n", original, emulated);
	emulated = ft_printf("nulo_s=%s nulo_p=%p\n", (char *)NULL, (void *)NULL);
	original = printf("nulo_s=%s nulo_p=%p\n", (char *)NULL, (void *)NULL);
	ft_printf("Test 3 (nulos) -> original=%d emulated=%d\n\n", original, emulated);
	emulated = ft_printf("vacio=[%s] cero_d=%d cero_x=%x\n", "", 0, 0);
	original = printf("vacio=[%s] cero_d=%d cero_x=%x\n", "", 0, 0);
	ft_printf("Test 4 (vacios y ceros) -> original=%d emulated=%d\n\n", original, emulated);
	emulated = ft_printf("");
	original = printf("");
	ft_printf("Test 5 (vacio total) -> original=%d emulated=%d\n", original, emulated);
	return (0);
}
