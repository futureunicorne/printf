/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:37:16 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:41:25 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_record_prec(char *s)
{
	int i;
	int j;
	int flag;
	int	res;
	char *s1;


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

int ft_record_chain(char *s)
{
	char *s1;
	int i;
	int j;
	int res;

	i = 0;
	res = 0;
	s1 = ft_strnew(ft_strlen(s));
	while (s[i] != '\0' && s[i] != '.')
	{
		if (s[i] >= 48 && s[i] <= 57)
		{
			j = 0;
			while (s[i] >= 48 && s[i] <= 57)
			{
				s1[j] = s[i];
				j++;
				i++;
			}
			if (s[i] == '.')
			{
				res = ft_atoi((const char*)s1);
				return (res);
			}
		}
		i++;
	}
	res = ft_atoi((const char*)s1);
	return (res);
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
