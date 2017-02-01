/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 13:16:12 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr1(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return ((int)ft_strlen(s));
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (0);
}

size_t	ft_strnlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnstr(char const *s, int n)
{
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	if (s)
		write(1, s, n);
	return ((int)n);
}

int	ft_putstr_f(char *s, va_list *p)
{

	char	*arg;
	int		nb;
	int		val;
	int		diff;
	int		check_type;

	nb = 0;
	diff = 0;
	check_type = 1;
	val = 0;
	arg = va_arg(*p, char*);
	if (arg != NULL)
		nb = ft_strlen(arg);
	else
		nb = 6;
	diff = ft_str_size(s,(void*)arg, check_type);
	ft_handle_str(s, arg, check_type);
	val = val + ft_size_chain_str(s, nb, diff, arg);
	val = val + ft_size_chain_str_plus(s, nb, diff, arg);
	return (val);
}
