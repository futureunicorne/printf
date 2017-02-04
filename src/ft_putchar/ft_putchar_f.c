/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:44 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 20:17:54 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putchar_f(char *s, va_list *p)
{
	int 	arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_long(s) == 'l')
	{
		ptr.val = ft_putchar_maj_f(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, int);
	ptr.nb = 1;
	ptr.diff = ft_char_size(s, ptr.check_type);
	ft_handle_char(s, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_char(s, ptr.nb, ptr.diff);
	ft_putchar(arg);
	ptr.val = ptr.val + ft_size_chain_char_plus(s, ptr.nb, ptr.diff);
	return (ptr.val + ptr.nb);
}
