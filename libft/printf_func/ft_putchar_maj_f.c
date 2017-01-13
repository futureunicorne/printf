/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:22 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/13 17:41:51 by hel-hadi         ###   ########.fr       */
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
	if (c <= 2047)
	{
		d =  (d >> 6 | 0xC0);
		c = ((c & 0x3F) | 0x80);
		c = (c << 8 | d);
		d = 2;
	}
	if (c <= 65535)
	{
		ft_putchar((c >> 12) | 0xE0); //224
		ft_putchar(((c >> 6) & 0x3F) | 0x80); // 63 et 128
		ft_putchar((c & 0x3F) | 0x80); // 63 et 1280
		d = 3;
	}
//	ft_putnbr(c)
		write(1, &c, d);
}

int	ft_putchar_maj_f(va_list *p)
{
	ft_putchar_maj(va_arg(*p, wchar_t));
	return (0);
}


void	ft_putchar_maji(wchar_t c)
{
	if (c <= 0x7F) // 127  1 octet
		ft_putchar(c);
	else if (c <= 0x7FF) //2047 2 octet
	{
		ft_putchar((c >> 6) | 0xC0);   // 192
		ft_putchar((c & 0x3F) | 0x80); // 63 et 128
	}
	else if (c <= 0xFFFF) // 65535  3octet
	{
		ft_putchar((c >> 12) | 0xE0); //224
		ft_putchar(((c >> 6) & 0x3F) | 0x80); // 63 et 128
		ft_putchar((c & 0x3F) | 0x80); // 63 et 1280

	}
	else if (c <= 0x10FFFF) // 1114111   4 octet
	{
		ft_putchar((c >> 18) | 0xF0); //240
		ft_putchar(((c >> 12) & 0x3F) | 0x80);  //63 et 128
		ft_putchar(((c >> 6) & 0x3F) | 0x80);	//63 et 128
		ft_putchar((c & 0x3F) | 0x80);			//63 et 128
	}
}
