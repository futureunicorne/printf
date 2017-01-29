/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/29 16:42:18 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strwlen(wchar_t *s)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] <= 127)
			cpt++;
		else if (s[i] <= 2047)
			cpt += 2;
		else if (s[i] <= 65535)
			cpt += 3;
		else if (s[i] <= 1114111)
			cpt += 4;
		i++;
	}
	return (cpt);
}

void	ft_putstr_maj(wchar_t *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar_maj(s[i]);
		i++;
	}
}

void	ft_putnstr_maj(wchar_t *s, int n)
{
	int i;

	i = 0;
	while ((ft_strwclen(s[i]) + i) <= n - 3)
	{
		ft_putchar_maj(s[i]);
		i = i + ft_strwclen(s[i]);
	}
}

int	ft_putstr_maj_f(char *s, va_list *p)
{
	wchar_t *arg;
	int		nb;
	int		diff;
	int		check_type;

	nb = 0;
	diff = 0;
	check_type = 1;
	arg = va_arg(*p, wchar_t*);
	nb = ft_strwlen(arg);
	diff = ft_str_size(s, (void*)arg, check_type);
	ft_handle_str(s, (void*)arg, check_type);
	ft_size_chain_str_maj(s, nb, diff, arg);
	ft_size_chain_str_plus(s, nb, diff);
	return (0);
}
