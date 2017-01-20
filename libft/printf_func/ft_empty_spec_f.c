/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_spec_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:47:47 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_empty_spec(char *str)
{
	ft_putchar('%');
}

int	ft_empty_spec_f(char *s, va_list *p)
{
	char *arg;
	int nb;
	int diff;
	int	check_type;


	diff = 0;
	nb = 0;
	check_type = 1;
	arg = va_arg(*p, char*);
	nb = ft_strlen(arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_handle_flag(s, arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_empty_spec(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
