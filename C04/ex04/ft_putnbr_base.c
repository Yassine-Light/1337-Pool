/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 16:22:56 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/23 10:26:11 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_base(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base_len < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < base_len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	convert(long nb, char *buff, char *base, int base_len)
{
	int	i;

	i = 0;
	if (nb == 0)
		buff[i++] = base[0];
	else
	{
		while (nb > 0)
		{
			buff[i++] = base[nb % base_len];
			nb /= base_len;
		}
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	char	buff[33];
	int		i;
	int		base_len;

	i = 0;
	nb = nbr;
	base_len = ft_strlen(base);
	if (!(check_base(base, base_len)))
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	i = convert(nb, buff, base, base_len);
	while (i > 0)
		write(1, &buff[--i], 1);
}
