/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_b3_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 18:37:46 by criredon          #+#    #+#             */
/*   Updated: 2026/08/07 18:37:49 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	emulated;
	int	original;

	emulated = ft_printf("Num: %d\n", 423);
	original = printf("Num: %d\n", 423);
	ft_printf("Test 0 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("Min: %i\n", INT_MIN);
	original = printf("Min: %i\n", INT_MIN);
	ft_printf("Test 1 -> original=%d emulated=%d\n", original, emulated);
	return (0);
}
