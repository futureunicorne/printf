/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:48:08 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int	diff;
	int	check_type;

	check_type = 1;
	arg = va_arg(*p, int);
	nb = 1;
	diff = ft_flag_size(s, (void*)arg);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_putchar(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
