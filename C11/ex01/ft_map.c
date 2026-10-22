/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:15:44 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/08/04 18:24:59 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*copy;

	i = 0;
	copy = malloc(sizeof(int) * length);
	while (i < length)
	{
		copy[i] = tab[i];
		copy[i] = f(copy[i]);
		i++;
	}
	return (copy);
}
