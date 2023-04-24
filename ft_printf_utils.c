/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:44 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 16:01:58 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	write_string(char *str)
{
	if (!str)
		str = NULLSTRING;
	return (write(1, str, ft_strlen(str)));
}

int	write_integer(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	write_pointer(unsigned long long int n, int is_upper)
{
	char	*str;
	int		len;

	if (n == 0)
	{
		ft_putstr_fd(NULLPOINTER, 1);
		return (ft_strlen(NULLPOINTER));
	}
	str = ft_itoa_16(n, is_upper);
	len = ft_strlen(str);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(str, 1);
	free(str);
	return (len + 2);
}

int	write_hex(unsigned int n, int is_upper)
{
	char	*str;
	int		len;

	str = ft_itoa_16(n, is_upper);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	write_unsigned(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_uitoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
