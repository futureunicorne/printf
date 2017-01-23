/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:16:35 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/23 15:08:41 by hel-hadi         ###   ########.fr       */
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
		ft_putchar(d);
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

int	ft_size_chain_plus_base(char *s, int t_arg, int diff)
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
	if (ft_check_space(s) == 1 && nbr && ft_check_more(s) == 0)
		len -= 1;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}


int	ft_size_chain_add(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	int flag;
	char d;

	nbr = ft_record_chain(s);
	i = 0;
	flag = 0;
	if (ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1)
	{
		ft_putstr("0x");
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
	{
		len = len;
		d = '0';
	}
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	if (nbr && flag == 0)
		ft_putstr("0x");
	return (i);
}



int	ft_size_chain_base(char *s, int t_arg, int diff, char base)
{
	int nbr;
	int i;
	int len;
	int flag;
	char d;

	nbr = ft_record_chain(s);
	flag  = 0;
	i = 0;
	if (ft_check_space(s) == 1 && nbr && ft_check_more(s) == 0 && ft_check_less(s) == 1)
		ft_putchar(' ');
	if ((ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1) && ft_check_more(s) == 1)
	{
		ft_putchar(base);
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
	{
		d = '0';
	}
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	if (flag == 0 && ft_check_more(s) == 1)
		ft_putchar(base);
	return (i);
}

int	ft_size_chain_hexa(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	int flag;
	char d;

	nbr = ft_record_chain(s);
	i = 0;
	flag = 0;
	if ((ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1) && ft_check_dieses(s) == 1)
	{
		ft_putstr("0x");
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
	{
		len = len;
		d = '0';
	}
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	if (flag == 0 && ft_check_dieses(s) == 1)
	{
		ft_putstr("0x");
	}
	return (i);
}


int	ft_size_chain_oct(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	int flag;
	char d;

	nbr = ft_record_chain(s);
	i = 0;
	flag = 0;
	if ((ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1) && ft_check_dieses(s) == 1)
	{
		ft_putstr("0");
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
	{
		len = len;
		d = '0';
	}
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	if (flag == 0 && ft_check_dieses(s) == 1)
	{
		ft_putstr("0");
	}
	return (i);
}

int	ft_size_chain_hexa_maj(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;
	int flag;
	char d;

	nbr = ft_record_chain(s);
	i = 0;
	flag = 0;
	if ((ft_check_less(s) == 1 || ft_check_zero(s, nbr) == 1) && ft_check_dieses(s) == 1)
	{
		ft_putstr("0X");
		flag = 1;
	}
	if (ft_check_less(s) == 1)
		return (0);
	if (t_arg > nbr)
		return (0);
	len = nbr - t_arg - diff;
	if (ft_check_less(s) == 1)
		return (0);
	if (ft_check_zero(s, nbr) == 1)
	{
		len = len;
		d = '0';
	}
	if (ft_check_zero(s, nbr) == 0)
		d = ' ';
	while (i < len)
	{
		ft_putchar(d);
		i++;
	}
	if (flag == 0 && ft_check_dieses(s) == 1)
	{
		ft_putstr("0X");
	}
	return (i);
}
