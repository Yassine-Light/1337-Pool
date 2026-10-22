/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:22:10 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/28 14:45:13 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ar_ptr;
	int	i;
	int	j;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	ar_ptr = malloc(sizeof(int) * (max - min));
	if (!ar_ptr)
		return (-1);
	i = 0;
	j = min;
	while (j < max)
	{
		ar_ptr[i] = j;
		j++;
		i++;
	}
	*range = ar_ptr;
	return (max - min);
}
