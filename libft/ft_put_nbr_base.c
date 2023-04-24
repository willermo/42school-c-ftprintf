/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 00:54:51 by doriani           #+#    #+#             */
/*   Updated: 2023/04/24 14:06:08 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_put_nbr_base(long long int n, int base)
{
	int	len;
	int	count;

	len = ft_strlen(base);
	count = 0;
	if (n >= (unsigned long long)len)
	{
		count += ft_put_nbr_base(n / len, base);
		count += ft_put_nbr_base(n % len, base);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
