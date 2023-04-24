/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:10:56 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 15:52:13 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# ifdef __APPLE__
#  define NULLSTRING "(null)"
#  define NULLPOINTER "0x0"
# else
#  define NULLSTRING "(null)"
#  define NULLPOINTER "(nil)"
# endif

int	ft_printf(const char *str, ...);
int	write_string(char *str);
int	write_pointer(unsigned long long int n, int is_upper);
int	write_integer(int n);
int	write_unsigned(unsigned int n);
int	write_hex(unsigned int n, int is_upper);
#endif
