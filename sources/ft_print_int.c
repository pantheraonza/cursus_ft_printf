/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:16:51 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:16:53 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_int(int n)
{
	long			nbr_long;
	unsigned long	nbr_unsigned;
	int				bytes;
	int				sign;

	nbr_long = (long)n;
	bytes = 0;
	sign = 0;
	if (nbr_long < 0)
	{
		if (ft_print_char('-') < 0)
			return (-1);
		nbr_long = -nbr_long;
		sign = 1;
	}
	nbr_unsigned = (unsigned long)nbr_long;
	bytes = ft_print_nbr(nbr_unsigned, "0123456789");
	if (bytes < 0)
		return (-1);
	return (bytes + sign);
}

/*
** ft_print_int — handles the sign for %d and %i, then delegates the digits.
** It is the wrapper that adds the '-' and solves the INT_MIN trap; the
** actual digits are printed by ft_print_nbr. Returns bytes written or -1.
**
** int ft_print_int(int n)
**   n : the signed integer to print (any value from INT_MIN to INT_MAX).
** nbr_long = (long)n;
**     Widen the int to long BEFORE touching the sign. This is the key step
**     for INT_MIN: negating it as an int would overflow, but as a long the
**     magnitude +2147483648 fits safely.
** bytes = 0;
**     Counter for the digits printed by the engine.
** sign = 0;
**     Remembers whether a '-' was written (0 = no, 1 = yes). Needed because
**     the unsigned value can never be negative, so the sign must be tracked
**     separately to add its byte to the final count.
** if (nbr_long < 0)
**     Is the number negative? Only then handle the sign.
**     if (ft_print_char('-') < 0)
**         return (-1);
**         Write the minus sign; propagate -1 if that write fails.
**     nbr_long = -nbr_long;
**         Make it positive. Safe here because nbr_long is already a long.
**     sign = 1;
**         Record that one sign byte was written.
** nbr_unsigned = (unsigned long)nbr_long;
**     Convert the now-positive value to unsigned long, the type the engine
**     expects. Done on every path (negative already fixed, or positive).
** bytes = ft_print_nbr(nbr_unsigned, "0123456789");
**     Delegate the digits to the shared engine, in base 10.
** if (bytes < 0)
**     return (-1);
**     The engine failed to write: propagate the error.
** return (bytes + sign);
**     Total = digits printed + the sign byte (0 or 1).
*/
