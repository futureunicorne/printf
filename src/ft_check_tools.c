/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:21:04 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 15:52:50 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_less(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_more(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_space(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_dieses(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_zero(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '.')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			if (s[i] == '0')
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
