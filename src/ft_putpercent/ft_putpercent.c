/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/04 17:20:20 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putpercent_f(char *s, va_list *p)
{
	char 	*arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.nb = 1;
	arg = "%";
	ptr.diff = ft_str_size(s,(void*)arg, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_str(s, ptr.nb, ptr.diff, arg);
	ptr.val = ptr.val + ft_size_chain_str_plus(s, ptr.nb, ptr.diff, arg);
	return (ptr.val);
}
