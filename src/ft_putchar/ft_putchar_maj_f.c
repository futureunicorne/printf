/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/07 08:36:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	else if (arg <= 1114111)
		nb = 4;
	return (nb);
}

void	ft_putchar_maj2(t_wch *wch)
{
	if (wch->c <= 127)
		wch->d = 1;
	else if (wch->c <= 2047)
	{
		wch->d =  (wch->d >> 6 | 0xC0);
		wch->c = ((wch->c & 0x3F) | 0x80);
		wch->c = (wch->c << 8 | wch->d);
		wch->d = 2;
	}
	else if (wch->c <= 65535)
	{
		wch->c = (((wch->c & 0x3F) | 0x80) << 16);
		wch->d = ((((wch->d & 0xFC0) >> 6) | 0x80) << 8);
		wch->e = ((wch->e >> 12) | 0xE0);
		wch->c = ((wch->e | wch->d) | wch->c);
		wch->d = 3;
	}
	else if (wch->c <= 1114111)
	{
		wch->c = (((wch->c & 0x3F) | 0x80) << 24);
		wch->d = ((((wch->d & 0xFC0) >> 6) | 0x80) << 16);
		wch->e = (((wch->e >> 12) | 0x80) << 8);
		wch->c = (((wch->c | wch->d) | wch->e) | 0xF0);
		wch->d = 4;
	}
}

void	ft_putchar_maj(wchar_t b)
{
	t_wch wch;

	ft_memset(&wch, 0, sizeof(t_wch));
	wch.c = b;
	wch.d = b;
	wch.e = b;
	ft_putchar_maj2(&wch);
	write(1, &wch.c, wch.d);
}

int		ft_putchar_maj_f(char *s, va_list *p)
{
	wchar_t arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	arg = va_arg(*p, wchar_t);
	ptr.nb = ft_strwclen(arg);
	ptr.check_type = 1;
	ptr.diff = ft_char_size(s, ptr.check_type);
	ft_handle_char(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_char(s, ptr.nb, ptr.diff);
	ft_putchar_maj(arg);
	ptr.val = ptr.val + ft_size_chain_char_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
