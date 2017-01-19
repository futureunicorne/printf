/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:46:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 08:49:07 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../printf.h"

int	ft_putplus(char *s, void *arg)
{
	int i;
	int flag;
	int nb;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1],s[i + 2]);
	if (((long)arg > 2147483647 || (long)arg < 0) && flag == 3)
		return (0);
	if (arg >= 0 && (flag == 3 || flag == 8))
	{
		ft_putchar('+');
		return (1);
	}
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

int	ft_putspace(int auth, int flag, int check_type)
{
	if (auth == 1 && flag == 0 && check_type == 0)
		ft_putchar(' ');
	return (0);
}
int ft_handle_flag(char *s, void *arg, int check_type)
{
	int i;
	t_pos pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == '-' && pos.flag2 == 0)
		{
			pos.flag2 = 1;
			pos.flag = 1;
		}
		else if (s[i] == '+' && pos.flag1 == 0)
		{
			ft_putplus(s, arg);
			pos.flag1 = 1;
			pos.flag = 1;
		}
		else if (s[i] == ' ')
			pos.auth = 1;
		else if (s[i] == '#' && pos.flag3 == 0)
		{
			ft_putdieses(s);
			pos.flag3 = 1;
			pos.flag = 1;
		}
		i++;
	}
	ft_putspace(pos.auth, pos.flag, check_type);
	return (0);
}
