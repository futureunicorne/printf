/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_spec_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:06:10 by hel-hadi         ###   ########.fr       */
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

	diff = 0;
	nb = 0;
	arg = va_arg(*p, char*);
	nb = ft_strlen(arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, arg);
	ft_empty_spec(arg);
	return (0);
}
