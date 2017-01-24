/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:21:04 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:41:26 by hel-hadi         ###   ########.fr       */
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

int	ft_check_zero(char *s, int nb)
{
	char	*str;
	int		i;
	int		j;

	str = ft_itoa(nb);
	i = 0;
	while (s && (s[i] != '0'))
		i++;
	while (s[i])
	{
		j = 0;
		while (s[i + j] == str[j])
		{
			if (str[j  + 1] == '\0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
