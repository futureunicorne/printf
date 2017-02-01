/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/31 20:32:47 by hel-hadi         ###   ########.fr       */
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
	int diff;
	int	check_type;


	diff = 0;
	nb = 1;
	arg = va_arg(*p, char*);
	ft_putpercent(arg);
	return (0);
}
