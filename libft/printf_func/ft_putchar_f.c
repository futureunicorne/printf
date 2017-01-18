/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 14:54:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int	diff;

	arg = va_arg(*p, int);
	nb = 1;
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_putchar(arg);
	return (0);
}
