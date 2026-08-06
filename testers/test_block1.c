/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_block1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:22:04 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:22:06 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	emulated;
	int	original;

	emulated = ft_printf("Hola %c y %%\n", 'A');
	original = printf("Hola %c y %%\n", 'A');
	printf("Test 0 -> original=%d emulated=%d\n", original, emulated);
	emulated = ft_printf("%c\n", 'Z');
	original = printf("%c\n", 'Z');
	printf("Test 1 -> original=%d emulated=%d\n", original, emulated);
	return (0);
}

//Block 1: Test with %c and %% conversion specifiers.
