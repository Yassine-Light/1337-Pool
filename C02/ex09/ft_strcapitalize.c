/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylaghrib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 18:56:58 by ylaghrib          #+#    #+#             */
/*   Updated: 2026/07/20 15:37:06 by ylaghrib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	ft_is_alpha_numeric(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	word;
	int	i;

	ft_strlowcase(str);
	word = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (word && (str[i] >= 'a' && str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
			word = 0;
		}
		else if (ft_is_alpha_numeric(str[i]))
			word = 0;
		else
			word = 1;
		i++;
	}
	return (str);
}
