/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <ylaghrib@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:17:10 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/08/05 09:33:28 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	result;
	int	count;

	i = 0;
	count = 0;
	result = 0;
	while (i < length)
	{
		result = f(tab[i]);
		if (result != 0)
			count++;
		i++;
	}
	return (count);
}
