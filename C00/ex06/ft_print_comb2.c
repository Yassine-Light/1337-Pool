/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 11:30:47 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/16 14:49:30 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_sequence(char tens, char ones)
{
	write(1, &tens, 1);
	write(1, &ones, 1);
	return ;
}

void	ft_print_comb2(void)
{
	int		num1;
	int		num2;
	char	tens;
	char	ones;

	num1 = 0;
	while (num1 <= 98)
	{
		num2 = num1 + 1;
		while (num2 <= 99)
		{
			tens = num1 / 10 + '0';
			ones = num1 % 10 + '0';
			print_sequence(tens, ones);
			write(1, " ", 1);
			tens = num2 / 10 + '0';
			ones = num2 % 10 + '0';
			print_sequence(tens, ones);
			if (num1 != 98 || num2 != 99)
				write(1, ", ", 2);
			num2++;
		}
		num1++;
	}
}
