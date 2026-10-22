/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:38:28 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/28 12:54:20 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ar_ptr;
	int	i;
	int	j;

	if (min >= max)
		return (NULL);
	ar_ptr = malloc(sizeof(int) * (max - min));
	if (!ar_ptr)
		return (NULL);
	i = 0;
	j = min;
	while (j < max)
		ar_ptr[i++] = j++;
	return (ar_ptr);
}
