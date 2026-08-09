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
	int	emul;
	int	orig;
	int	x;

	x = 42;
	emul = ft_printf("Todo: c=%c s=%s d=%d u=%u x=%x X=%X p=%p pct=%%\n",
			'A', "hola", -42, 42, 255, 255, &x);
	orig = printf("Todo: c=%c s=%s d=%d u=%u x=%x X=%X p=%p pct=%%\n",
			'A', "hola", -42, 42, 255, 255, &x);
	ft_printf("Test 0 (mezcla) -> orig=%d emul=%d\n\n", orig, emul);
	emul = ft_printf("dmin=%d dmax=%d imin=%i\n", INT_MIN, INT_MAX, INT_MIN);
	orig = printf("dmin=%d dmax=%d imin=%i\n", INT_MIN, INT_MAX, INT_MIN);
	ft_printf("Test 1 (bordes int) -> orig=%d emul=%d\n\n", orig, emul);
	emul = ft_printf("umax=%u xmax=%x Xmax=%X\n", UINT_MAX, UINT_MAX, UINT_MAX);
	orig = printf("umax=%u xmax=%x Xmax=%X\n", UINT_MAX, UINT_MAX, UINT_MAX);
	ft_printf("Test 2 (bordes unsig) -> orig=%d emul=%d\n\n", orig, emul);
	emul = ft_printf("nulo_s=%s nulo_p=%p\n", (char *) NULL, (void *) NULL);
	orig = printf("nulo_s=%s nulo_p=%p\n", (char *) NULL, (void *) NULL);
	ft_printf("Test 3 (nulos) -> orig=%d emul=%d\n\n", orig, emul);
	emul = ft_printf("vacio=[%s] cero_d=%d cero_x=%x\n", "", 0, 0);
	orig = printf("vacio=[%s] cero_d=%d cero_x=%x\n", "", 0, 0);
	ft_printf("Test 4 (vacios y ceros) -> orig=%d emul=%d\n\n", orig, emul);
	return (0);
}
