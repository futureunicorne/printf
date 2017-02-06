/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:37:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 16:16:22 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_record_prec(char *s)
{
	int		i;
	int		j;
	int		flag;
	int		res;
	char	*s1;

	i = 0;
	j = 0;
	flag = 0;
	s1 = ft_strnew(ft_strlen(s));
	while (s[i] && s[i] != '.')
		i++;
	while (s[i] && flag == 0)
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			s1[j] = s[i];
			j++;
			i++;
			flag = 1;
		}
		i++;
	}
	res = ft_atoi((const char*)s1);
	return (res);
}

int	ft_record_chain(char *s)
{
	t_chk chk;

	ft_memset(&chk, 0, sizeof(t_chk));
	chk.s1 = ft_strnew(ft_strlen(s));
	while (s[chk.i] != '\0' && s[chk.i] != '.')
	{
		if (s[chk.i] >= 48 && s[chk.i] <= 57)
		{
			chk.j = 0;
			while (s[chk.i] >= 48 && s[chk.i] <= 57)
			{
				chk.s1[chk.j] = s[chk.i];
				chk.j++;
				chk.i++;
			}
			if (s[chk.i] == '.')
			{
				chk.res = ft_atoi((const char*)chk.s1);
				return (chk.res);
			}
		}
		chk.i++;
	}
	chk.res = ft_atoi((const char*)chk.s1);
	return (chk.res);
}

int	ft_check_point(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_long(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((s[i] == 'l' || s[i] == 'h' || s[i] == 'j' || s[i] == 'z')
		&& check_ptr2(s[i + 1]))
			return (s[i]);
		if ((s[i] == 'l' || s[i] == 'h' || s[i] == 'j' || s[i] == 'z')
		&& (s[i] == 'l' || s[i] == 'h' || s[i] == 'j' || s[i] == 'z')
		&& check_ptr2(s[i + 2]))
			return (s[i]);
		i++;
	}
	return (0);
}
