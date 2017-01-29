/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/29 15:41:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putnstr(char const *s, int n)
{
	if (s)
		write(1, s, n);
	return ((int)ft_strlen(s));
}

int	ft_putstr_f(char *s, va_list *p)
{
	char	*arg;
	int		nb;
	int		diff;
	int		check_type;

	nb = 0;
	diff = 0;
	check_type = 1;
	arg = va_arg(*p, char*);
	nb = ft_strlen(arg);
	diff = ft_str_size(s,(void*)arg, check_type);
	ft_handle_str(s, arg, check_type);
	ft_size_chain_str(s, nb, diff, arg);
	ft_size_chain_str_plus(s, nb, diff);
	return (0);
}
