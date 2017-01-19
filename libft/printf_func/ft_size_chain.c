/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:16:35 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 08:19:32 by hel-hadi         ###   ########.fr       */
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
	s1[j] = '\0';
	res = ft_atoi(s1);
	return (res);
}

int	ft_size_chain(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

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
}
