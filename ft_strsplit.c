/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:02:37 by samatsum          #+#    #+#             */
/*   Updated: 2024/09/02 00:17:37 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	words(char const *str, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (words);
}

static	char	*allocate_memory(int letters)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (letters + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}

static	int	parse_and_allocate(char const *str, char c, char **res)
{
	int	i;
	int	j;
	int	letters;

	i = 0;
	j = 0;
	while (str[i])
	{
		letters = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			letters++;
			i++;
		}
		if (letters > 0)
		{
			res[j] = allocate_memory(letters);
			if (res[j++] == NULL)
				return (-1);
		}
	}
	return (j);
}

static	char	**memory_giver(char const *str, char c)
{
	char	**res;
	int		j;

	res = (char **)malloc(sizeof(char *) * (words(str, c) + 1));
	if (res == NULL)
		return (NULL);
	j = parse_and_allocate(str, c, res);
	if (j == -1)
		return (NULL);
	res[j] = 0;
	return (res);
}

char	**ft_strsplit(char const *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		str_number;
	int		size;

	if (str == NULL)
		return (NULL);
	size = words(str, c);
	res = memory_giver(str, c);
	if (res == NULL)
		return (NULL);
	i = 0;
	str_number = 0;
	while (str_number < size)
	{
		while (str[i] == c && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i])
			res[str_number][j++] = str[i++];
		res[str_number][j] = '\0';
		str_number++;
	}
	return (res);
}
