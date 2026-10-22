/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:20:13 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/30 14:35:41 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0' && c != charset[i])
		i++;
	return (charset[i] != '\0');
}

int	get_count_words(char *str, char *charset)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
			count_words++;
		i++;
	}
	return (count_words);
}

char	**spliting(char **splited, int *sep_index, char *str, char *charset)
{
	int	i;
	int	j;
	int	k;
	int	count_words;

	i = 0;
	count_words = get_count_words(str, charset);
	while (i < count_words)
	{
		k = sep_index[i];
		j = 0;
		while (str[j + k] != '\0' && (!is_sep(str[j + k], charset)))
			j++;
		splited[i] = malloc(sizeof(char) * (j + 1));
		j = 0;
		while (str[j + k] != '\0' && (!is_sep(str[j + k], charset)))
		{
			splited[i][j] = str[j + k];
			j++;
		}
		splited[i][j] = '\0';
		i++;
	}
	splited[i] = NULL;
	return (splited);
}

char	**ft_split(char *str, char *charset)
{
	char	**splited;
	int		*sep_index;
	int		i;
	int		j;
	int		count_words;

	count_words = get_count_words(str, charset);
	sep_index = malloc(sizeof(int) * (count_words + 1));
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (!is_sep(str[i], charset) && (i == 0 || is_sep(str[i - 1], charset)))
		{
			sep_index[j] = i;
			j++;
		}
		i++;
	}
	splited = malloc(sizeof(char *) * (count_words + 1));
	splited = spliting(splited, sep_index, str, charset);
	return (splited);
}
