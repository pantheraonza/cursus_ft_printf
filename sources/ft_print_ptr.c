/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:17:18 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:17:19 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../libft/libft.h"

int	ft_print_ptr(void *ptr)
{
	int		bytes;

	if (ptr == NULL)
		return (ft_print_str("(nil)"));
	if (ft_print_str("0x") < 0)
		return (-1);
	bytes = ft_utils_nbr((unsigned long)ptr, "0123456789abcdef");
	if (bytes < 0)
		return (-1);
	return (bytes + 2);
}
