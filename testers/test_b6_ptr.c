/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_b6_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 15:29:33 by criredon          #+#    #+#             */
/*   Updated: 2026/08/09 15:29:34 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		emulated;
	int		original;
	int		x;

	x = 42;
	emulated = ft_printf("ptr: %p\n", &x);
	original = printf("ptr: %p\n", &x);
	ft_printf("Test 0 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("nil: %p\n", (void *)0);
	original = printf("nil: %p\n", (void *)0);
	ft_printf("Test 1 -> original=%d emulated=%d\n", original, emulated);
	return (0);
}
