/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:59:04 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 01:01:41 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_buffer_size(unsigned long long int n, int base)
{
	int	size;

	if (n == 0)
		return (2);
	size = 1;
	while (n != 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(unsigned long long int n, int base, int uppercase)
{
	char	*str;
	int		i;
	char	*base_str;

	base_str = "0123456789abcdef";
	if (uppercase)
		base_str = "0123456789ABCDEF";
	i = 0;
	str = malloc(sizeof(char) * get_buffer_size(n, base));
	if (!str)
		return (NULL);
	while (n / base != 0)
	{
		str[i++] = base_str[n % base];
		n /= base;
	}
	str[i++] = base_str[n % base];
	str[i] = '\0';
	return (ft_strrev(str));
}
