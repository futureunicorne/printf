/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:46:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/17 18:15:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putplus(char *s, void *arg)
{
	int i;
	int flag;
	int nb;

	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1],s[i + 2]);
	if (((long)arg > 2147483647 || (long)arg < 0) && flag == 3)
		return (0);
	if (arg >= 0 && (flag == 3 || flag == 8))
		ft_putchar('+');
	return (0);
}

int	ft_putdieses(char *s)
{
	int i;
	int flag;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1],s[i + 2]);
	if (flag == 5) //x
		ft_putstr("0x");
	else if (flag == 7) // o
		ft_putchar('0');
	else if (flag == 9) // X
		ft_putstr("0X");
	else if (flag == 10) // O
		ft_putchar('0');
	return (0);
}

int ft_handle_flag(char *s, void *arg)
{
	int i;
	int flag;
	int auth;

	i = 0;
	flag = 0;
	auth = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == '-')
			flag = 1;
		else if (s[i] == '+')
		{
			flag = 1;
			ft_putplus(s, arg);
		}
		else if (s[i] == ' ')
			auth = 1;
		else if (s[i] == '#')
		{
			ft_putdieses(s);
			flag = 1;
		}
		i++;
	}
	if (auth == 1 && flag == 0)
		ft_putchar(' ');
	return (0);
}
