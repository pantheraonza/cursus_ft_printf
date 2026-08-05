/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: criredon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:23:09 by criredon          #+#    #+#             */
/*   Updated: 2026/08/05 17:23:11 by criredon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int ft_printf(char const *format, ...);
int ft_convert(char conv_type, va_list args);
int ft_print_char(char c);
// int ft_print_string();
// int ft_print_number(int n);

#endif

