/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:48:19 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strwclen(wchar_t arg)
{
	int nb;

	nb = 0;
	if (arg <= 127)
		nb = 1;
	else if (arg <= 2047)
		nb = 2;
	else if (arg <= 65535)
		nb = 3;
	return (nb);
}

void	ft_putchar_maj(wchar_t c)
{
	wchar_t d;
	wchar_t e;

	d = c;
	e = c;
	if (c <= 127)
		d = 1;
	else if (c <= 2047)
	{
		d =  (d >> 6 | 0xC0);
		c = ((c & 0x3F) | 0x80);
		c = (c << 8 | d);
		d = 2;
	}
	else if (c <= 65535)
	{
		c = (((c & 0x3F) | 0x80) << 16);
		d = ((((d & 0xFC0) >> 6) | 0x80) << 8);
		e = ((e >> 12) | 0xE0);
		c = ((e | d) | c);
		d = 3;
	}
	write(1, &c, d);
}

int	ft_putchar_maj_f(char *s, va_list *p)
{
	wchar_t arg;
	int		nb;
	int		diff;
	int		check_type;


	arg = va_arg(*p, wchar_t);
	nb = ft_strwclen(arg);
	check_type = 0;
	diff = ft_flag_size(s, (void*)arg);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_putchar_maj(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
