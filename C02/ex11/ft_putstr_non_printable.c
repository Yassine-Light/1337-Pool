/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 09:50:09 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/21 15:53:31 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_convert_to_hex(char str)
{
	char	*hex;
	char	tens;
	char	ones;

	hex = "0123456789abcdef";
	tens = hex[(unsigned char)str / 16];
	ones = hex[(unsigned char)str % 16];
	write(1, "\\", 1);
	write(1, &tens, 1);
	write(1, &ones, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 32) || str[i] >= 127)
			ft_convert_to_hex(str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
