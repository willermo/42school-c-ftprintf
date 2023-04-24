/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 00:30:56 by doriani           #+#    #+#             */
/*   Updated: 2023/04/14 00:31:19 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;

	start = str;
	end = str;
	while (*(end + 1))
		end++;
	while (end > start)
		ft_swap(start++, end--);
	return (str);
}
