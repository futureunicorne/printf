/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 16:43:01 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putstr1(char const *s)
{
	if (s)
	{
		write(1, s, ft_strlen(s));
		return ((int)ft_strlen(s));
	}
	else
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (0);
}

size_t	ft_strnlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_putnstr(char const *s, int n)
{
	if (n > ft_strlen(s))
		n = ft_strlen(s);
	if (s)
		write(1, s, n);
	return ((int)n);
}

int		ft_putstr_f(char *s, va_list *p)
{
	char	*arg;
	t_ptr	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	if (ft_check_long(s) == 'l')
	{
		ptr.val = ft_putstr_maj_f(s, p);
		return (ptr.val);
	}
	ptr.check_type = 1;
	arg = va_arg(*p, char*);
	if (arg != NULL)
		ptr.nb = ft_strlen(arg);
	else
		ptr.nb = 6;
	ptr.diff = ft_str_size(s, (void*)arg, ptr.check_type);
	ft_handle_str(s, arg, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_str(s, ptr.nb, ptr.diff, arg);
	ptr.val = ptr.val + ft_size_chain_str_plus(s, ptr.nb, ptr.diff, arg);
	return (ptr.val);
}
