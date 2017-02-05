/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 23:56:28 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 00:00:10 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_f(char *s, va_list *p)
{
   unsigned		arg;
   t_ptr 		ptr;

   ft_memset(&ptr, 0, sizeof(t_ptr));
   if (ft_check_long(s))
   {
	   if (ft_check_long(s) == 'l')
		   ptr.val = ft_putbin_l(s, p);
	   else if (ft_check_long(s) == 'h')
		   ptr.val = ft_putbin_h(s, p);
	   else if (ft_check_long(s) == 'j')
		   ptr.val = ft_putbin_j(s, p);
	   else if (ft_check_long(s) == 'z')
		   ptr.val = ft_putbin_z(s, p);
	   return (ptr.val);
   }
   ptr.check_type = 1;
   arg = va_arg(*p, unsigned);
   ptr.nb = ft_nbr_bin((unsigned)arg);
   ptr.diff = ft_bin_size(s, arg, ptr.check_type);
   ptr.val = ft_size_chain_bin(s, ptr.nb, ptr.diff, arg);
   ft_putbin(arg);
   ptr.val = ptr.val + ft_size_chain_bin_plus(s, ptr.nb, ptr.diff);
   return (ptr.val + ptr.nb);
}
