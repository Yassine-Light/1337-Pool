/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:31:42 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/23 11:32:33 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	buff[11];
	long	nbr;
	int		i;

	i = 0;
	nbr = nb;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (nbr > 0)
	{
		buff[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	while (i > 0)
		write(1, &buff[--i], 1);
}
