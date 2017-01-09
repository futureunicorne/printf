/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:16:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/08 21:43:29 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <printf.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	int long nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int check_flag(int c)
{
	if (c == 's')
		return (1);
	if (c == 'c')
		return (2);
	if (c == 'd')
		return (3);
	return (0);
}

int	ft_printf(char *str, ...)
{
	int (*pointeurSurFonction[4])(va_list *);
	int i;
	int flag;

	va_list ap;
	pointeurSurFonction[1] = &ft_putstr;
	pointeurSurFonction[2] = ft_putchar;
	pointeurSurFonction[3] = ft_putnbr;

	i = 0;
	flag = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = check_flag(str[i + 1]);
     		pointeurSurFonction[flag](&ap);
			i++;
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	ft_printf("%d", 43);
	return (0);
}

