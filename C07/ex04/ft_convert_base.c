/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 12:15:58 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/29 16:31:53 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);

int	is_valid(char *base, int base_len);

int	get_digit_index(char c, char *base);

int	count_numbers(long nb, int base_to_len);

int	convert_to_neg(long *nb);

int	atoi_base(char *str, char *base_from, int base_from_len)
{
	long	atoi;
	int		i;
	int		sign;
	int		digit_index;

	i = 0;
	sign = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	digit_index = get_digit_index(str[i], base_from);
	while (digit_index != -1)
	{
		atoi = atoi * base_from_len + digit_index;
		i++;
		digit_index = get_digit_index(str[i], base_from);
	}
	return ((int)(sign * atoi));
}

char	*putnbr_base(int nbr, char *base_to, int base_to_len)
{
	char	*buff;
	long	nb;
	int		digit_len;
	int		is_negative;
	int		len;

	nb = nbr;
	is_negative = convert_to_neg(&nb);
	digit_len = count_numbers(nb, base_to_len);
	len = digit_len + is_negative;
	buff = malloc(sizeof(char) * (len + 1));
	if (!buff)
		return (NULL);
	buff[len] = '\0';
	while (nb >= base_to_len)
	{
		buff[--len] = base_to[nb % base_to_len];
		nb /= base_to_len;
	}
	buff[--len] = base_to[nb];
	if (is_negative)
		buff[--len] = '-';
	return (buff);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	base_from_len;
	int	base_to_len;
	int	nb;

	base_from_len = ft_strlen(base_from);
	base_to_len = ft_strlen(base_to);
	if (!is_valid(base_from, base_from_len) || !is_valid(base_to, base_to_len))
		return (NULL);
	nb = atoi_base(nbr, base_from, base_from_len);
	return (putnbr_base(nb, base_to, base_to_len));
}
