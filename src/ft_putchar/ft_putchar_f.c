/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 14:54:14 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int val;
	int	diff;
	int	check_type;

	val = 0;
	check_type = 1;
	arg = va_arg(*p, int);
	nb = 1;
	diff = ft_char_size(s, check_type);
	ft_handle_char(s, check_type);
	val = val + ft_size_chain_char(s, nb, diff);
	ft_putchar(arg);
	val = val + ft_size_chain_char_plus(s, nb, diff);
	return (val + nb);
}
