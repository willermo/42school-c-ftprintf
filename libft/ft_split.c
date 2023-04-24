/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doriani <doriani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:22:23 by doriani           #+#    #+#             */
/*   Updated: 2023/04/04 21:05:55 by doriani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_tokens(char *str, char c)
{
	int	tokens;

	tokens = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			tokens++;
		while (*str && (*str != c))
			str++;
	}
	return (tokens);
}

static char	*add_token(char *str, char c, char **address)
{
	char	*token;
	char	*runner;
	char	*token_runner;

	while (*str && (*str == c))
		str++;
	runner = str;
	while (*str && (*str != c))
		str++;
	if (runner == str)
	{
		*address = 0;
		return (str);
	}
	token = (char *) malloc((str - runner + 1) * sizeof(char));
	if (!token)
		return (NULL);
	token_runner = token;
	while (runner < str)
		*token_runner++ = *runner++;
	*token_runner = '\0';
	*address = token;
	return (str);
}

char	**ft_split(char *str, char c)
{
	char	**strings;
	int		tokens;
	char	**strings_runner;

	if (!str)
		return (NULL);
	tokens = count_tokens(str, c);
	strings = (char **) malloc((tokens + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	strings_runner = strings;
	str = add_token(str, c, strings_runner++);
	if (!str)
		return (strings);
	tokens --;
	while (tokens-- >= 0)
	{
		str = add_token(str, c, strings_runner++);
		if (!str)
			return (strings);
	}
	return (strings);
}
