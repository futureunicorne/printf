/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_spec_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/17 16:08:36 by hel-hadi         ###   ########.fr       */
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

	arg = va_arg(*p, char*);
	ft_handle_flag(s, arg);
	ft_empty_spec(arg);
	return (0);
}
