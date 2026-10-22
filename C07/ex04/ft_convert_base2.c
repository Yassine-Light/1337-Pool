/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:29:07 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/29 16:32:51 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	is_valid(char *base, int base_len)
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

int	get_digit_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	count_numbers(long nb, int base_to_len)
{
	int	count;

	count = 1;
	while (nb >= base_to_len)
	{
		count++;
		nb = nb / base_to_len;
	}
	return (count);
}

int	convert_to_neg(long *nb)
{
	int	is_negative;

	is_negative = 0;
	if (*nb < 0)
	{
		*nb *= -1;
		is_negative = 1;
	}
	return (is_negative);
}
