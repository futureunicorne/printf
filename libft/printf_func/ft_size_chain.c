/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:16:35 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:59:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int ft_record_chain(char *s)
{
	char *s1;
	int i;
	int j;
	int res;

	i = 0;
	res = 0;
	s1 = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
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
		}
		i++;
	}
	res = ft_atoi((const char*)s1);
	return (res);
}
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


int	ft_size_chain(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	char d;


	if (ft_check_less(s) == 1)
		return (0);

	nbr = ft_record_chain(s);
	i = 0;
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_zero(s, nbr) == 1)
		d = '0';
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}

int	ft_size_chain_plus(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

	if (ft_check_less(s) == 0)
		return (0);
	nbr = ft_record_chain(s);
	i = 0;
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
