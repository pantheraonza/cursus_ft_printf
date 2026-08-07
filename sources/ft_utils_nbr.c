/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/07 16:33:34 by criredon          #+#    #+#             */
/*   Updated: 2026/08/07 16:33:36 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_nbr(unsigned long n, char *base)
{
	int				bytes;
	unsigned long	radix;

	bytes = 0;
	radix = ft_strlen(base);
	if (n >= radix)
	{
		bytes = ft_print_nbr(n / radix, base);
		if (bytes < 0)
			return (-1);
	}
	if (ft_print_char(base[n % radix]) < 0)
		return (-1);
	return (bytes + 1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int	bytes;

// 	bytes = ft_print_nbr(423, "0123456789");
// 	printf("  <- decimal 423 | bytes=%d\n", bytes);
// 	bytes = ft_print_nbr(0, "0123456789");
// 	printf("  <- decimal 0 | bytes=%d\n", bytes);
// 	bytes = ft_print_nbr(255, "0123456789abcdef");
// 	printf("  <- hexa de 255 (esperado ff) | bytes=%d\n", bytes);
// 	bytes = ft_print_nbr(255, "0123456789ABCDEF");
// 	printf("  <- HEXA de 255 (esperado FF) | bytes=%d\n", bytes);
// 	bytes = ft_print_nbr(4294967295, "0123456789");
// 	printf("  <- UINT_MAX | bytes=%d\n", bytes);
// 	return (0);
// }

/*
** ft_print_nbr — recursive number engine for every numeric conversion.
** Prints an unsigned long in the base defined by the 'base' alphabet
** and returns how many characters were written (or -1 on write error).
**
** int ft_print_nbr(unsigned long n, char *base)
** n     : the value to print, already positive (sign is handled outside).
**         It is 'unsigned long' so it fits INT_MIN's magnitude and UINT_MAX.
** base  : the alphabet of symbols. Its length IS the base:
**         "0123456789" -> base 10, "0123456789abcdef" -> base 16.
** bytes  = 0;
**     Counter for the characters written. Starts at zero.
** radix = ft_strlen(base);
**     The number of symbols in 'base'. This value is the numeric base
**     (10 or 16). Computed once and reused for '/' and '%'.
** if (n >= radix)
**     Does the number have more than one digit in this base?
**     If yes, the left-hand digits must be printed BEFORE the current one.
**     bytes = ft_print_nbr(n / radix, base);
**         Recurse on all digits except the last. 'n / radix' removes the
**         rightmost digit. The returned count is stored in 'bytes'.
**     if (bytes < 0)
**         return (-1);
**         A write failed deeper in the recursion: stop and propagate -1.
** ft_print_char(base[n % radix])
**     'n % radix' is the rightmost digit as a NUMBER (e.g. 12 in base 16).
**     Used as an index into 'base', it becomes the SYMBOL ('c' for 12).
**     This replaces the "+ '0'" trick and works for any base.
**     if (... < 0)
**         return (-1);
**         The write of the current digit failed: propagate -1.
** return (bytes + 1);
**     Total = digits printed by the recursion (bytes) + this digit (1).
**     The sum travels up the recursive calls to give the final count.
*/