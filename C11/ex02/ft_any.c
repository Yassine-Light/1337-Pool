/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 18:25:37 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/08/04 18:54:08 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (tab[i] != NULL)
	{
		res = f(tab[i]);
		if (res != 0)
			return (1);
		i++;
	}
	return (0);
}
