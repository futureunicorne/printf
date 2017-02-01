/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/01 15:18:48 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_putpercent(char *str)
{
	ft_putchar('%');
}

int	ft_putpercent_f(char *s, va_list *p)
{
	char *arg;
	int nb;
	int val;
	int diff;
	int	check_type;


	val = 0;
	diff = 0;
	nb = 1;
	arg = "%";
	diff = ft_str_size(s,(void*)arg, check_type);
	val = val + ft_size_chain_str(s, nb, diff, arg);
	val = val + ft_size_chain_str_plus(s, nb, diff, arg);
	return (val);
}
