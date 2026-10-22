/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: islakoua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:12:14 by islakoua          #+#    #+#             */
/*   Updated: 2026/08/05 11:11:57 by islakoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_add(int a, int b);
int	ft_sub(int a, int b);
int	ft_div(int a, int b);
int	ft_mul(int a, int b);
int	ft_mod(int a, int b);

int	ispace(char c)
{
	if (c >= 9 && c <= 13)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	long	num;
	long	s;
	int		i;

	s = 1;
	i = 0;
	num = 0;
	while (ispace(str[i]))
		i++;
	i--;
	while (str[++i] == '-' || str[i] == '+')
		if (str[i] == '-')
			s *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += (unsigned char)str[i] - '0';
		i++;
	}
	num *= s;
	return ((int)num);
}

int	ft_op(char op, char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	if (len != 1)
		return (-1);
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '/')
		return (2);
	if (op == '*')
		return (3);
	if (op == '%')
		return (4);
	return (-1);
}

void	ft_putnbr(int nb, int newline)
{
	long	n;

	n = (long)nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10, 0);
	write(1, &(char){n % 10 + '0'}, 1);
	if (newline)
		write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	a;
	int	op;
	int	b;
	int	(*f[5])(int, int);

	f[0] = ft_add;
	f[1] = ft_sub;
	f[2] = ft_div;
	f[3] = ft_mul;
	f[4] = ft_mod;
	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	op = ft_op(argv[2][0], argv[2]);
	b = ft_atoi(argv[3]);
	if (op == -1)
		write(1, "0\n", 2);
	else if (op == 2 && b == 0)
		write(1, "Stop : division by zero\n", 24);
	else if (op == 4 && b == 0)
		write(1, "Stop : modulo by zero\n", 22);
	else
		ft_putnbr((*f[op])(a, b), 1);
	return (0);
}
