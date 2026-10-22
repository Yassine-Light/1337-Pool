/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 10:54:06 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/21 09:31:10 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_first_column(long addr)
{
	char	*hex;
	char	buff[16];
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		buff[i] = hex[addr % 16];
		addr = addr / 16;
		i--;
	}
	write(1, &buff, 16);
	write(1, ": ", 2);
}

void	ft_second_column(unsigned char *str, int len)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16 && i < len)
	{
		write(1, &hex[str[i] / 16], 1);
		write(1, &hex[str[i] % 16], 1);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if ((i + 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
}

void	ft_third_column(unsigned char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if ((str[i] < 32) || (str[i] >= 127))
			write(1, ".", 1);
		else
			write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int				len;
	unsigned int	i;

	if (size == 0)
		return (addr);
	i = 0;
	while (i < size)
	{
		if (size - i >= 16)
			len = 16;
		else
			len = size - i;
		ft_first_column((long)addr + i);
		ft_second_column((unsigned char *)addr + i, len);
		ft_third_column((unsigned char *)addr + i, len);
		i += 16;
	}
	return (addr);
}
