/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 16:57:33 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/25 17:33:18 by ylaghrib         ###   ########.fr       */
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

int	get_base_index(char c, char *base)
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

int	ft_atoi(char *str, char *base, int base_len)
{
	int	i;
	int	sign;
	int	atoi;
	int	base_index;

	i = 0;
	sign = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	base_index = get_base_index(str[i], base);
	while (base_index != -1)
	{
		atoi = atoi * base_len + base_index;
		i++;
		base_index = get_base_index(str[i], base);
	}
	return (sign * atoi);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_len;
	int	atoi_max;

	base_len = ft_strlen(base);
	if (!check_base(base, base_len))
		return (0);
	atoi_max = ft_atoi(str, base, base_len);
	return (atoi_max);
}
