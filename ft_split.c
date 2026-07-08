/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srouhi <srouhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 14:46:35 by srouhi            #+#    #+#             */
/*   Updated: 2026/07/03 15:37:30 by srouhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	**free_array(char **array, size_t i)
{
	while (i--)
		free(array[i]);
	free(array);
	return (NULL);
}

static char	**fill_array(char **array, char const *s, char c, size_t words)
{
	size_t	i;
	size_t	len;
	size_t	j;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = 0;
		while (s[len] && s[len] != c)
			len++;
		array[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!array[i])
			return (free_array(array, i));
		j = 0;
		while (j < len)
			array[i][j++] = *s++;
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (words + 1));
	if (!array)
		return (NULL);
	return (fill_array(array, s, c, words));
}
