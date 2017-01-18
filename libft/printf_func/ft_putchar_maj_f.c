/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 14:58:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

	arg = va_arg(*p, wchar_t);
	if (arg <= 127)
		nb = 1;
	else if (arg <= 2047)
		nb = 2;
	else if (arg <= 65535)
		nb = 3;
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_putchar_maj(arg);
	return (0);
}
