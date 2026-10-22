/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 15:05:06 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/29 11:44:54 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	strlen_total(char **str, char *sep, int size)
{
	int	total_len;
	int	i;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(str[i]);
		i++;
	}
	total_len += ft_strlen(sep) * (size - 1);
	return (total_len);
}

char	*parse_join(char **strs, char *sep, char *join, int size)
{
	int		i;
	int		j;
	int		k;
	int		pos;

	i = 0;
	pos = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			join[pos++] = strs[i][j++];
		if (i < size - 1)
		{
			k = 0;
			while (sep[k] != '\0')
				join[pos++] = sep[k++];
		}
		i++;
	}
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;
	char	*null_size;
	int		total_len;

	if (size == 0)
	{
		null_size = malloc(sizeof(char));
		if (!null_size)
			return (NULL);
		*null_size = '\0';
		return (null_size);
	}
	total_len = strlen_total(strs, sep, size);
	join = malloc(sizeof(char) * (total_len + 1));
	if (!join)
		return (NULL);
	join = parse_join(strs, sep, join, size);
	join[total_len] = '\0';
	return (join);
}
