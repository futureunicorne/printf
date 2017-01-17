/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:46:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/17 10:35:38 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
int	ft_putspace(char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == ' ' && flag == 0)
		{
			ft_putchar(' ');
			flag = 1;
		}
		i++;
	}
	return (i);
}
*/

int	ft_putless(char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == '-' && flag == 0)
			flag = 1;
		i++;
	}
}

int ft_handle_flag(char *s, va_list *ap)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == '-' && flag == 0)
		{
			ft_putless(s);
			flag = 1;
		}
		else if (s[i] == '+' && flag == 0)
		{
			ft_putchar('+');
			flag = 1;
		}
		else if (s[i] == ' ' && flag == 0)
		{
			ft_putchar(' ');
			flag = 1;
		}
		else if (s[i] == ' ' && flag == 0)
		{
			ft_putdieses(char *s, va_list *ap);
			flag = 1;
		}
		i++;
	}
	return (0);
}
