/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 14:08:23 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_strwlen(wchar_t *s)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (s[i])
	{
		if (s[i] <= 127)
			cpt++;
		else if (s[i] <= 2047)
			cpt += 2;
		else if (s[i] <= 65535)
			cpt += 3;
		else if (s[i] <= 1114111)
			cpt += 4;
		i++;
	}
	return (cpt);
}

int	ft_putstr_maj(wchar_t *s)
{
	int i;

	i = 0;
	if (s == NULL)
		write(1, "(null)", 6);
	else
	{
		while (s[i])
		{
			ft_putchar_maj(s[i]);
			i++;
		}
	}
	return (i);
}

int	ft_putnstr_maj(wchar_t *s, int n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] && j < n)
	{
		j = ft_strwclen(s[i]) + j;
		if (j <= n)
			i++;
	}
	j = 0;
	while (j < i)
	{
		ft_putchar_maj(s[j]);
		j++;;
	}
	return (n);
}

int	ft_cptnstr(wchar_t *s, int n)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] && (j < n))
	{
		j = ft_strwclen(s[i]) + j;
		if (j <= n)
			i++;
	}
	j = 0;
	k = 0;
	while (j < i)
	{
		k = k + ft_strwclen(s[j]);
		j++;
	}
	return (k);
}

int	ft_putstr_maj_f(char *s, va_list *p)
{
	wchar_t *arg;
	t_ptr 	ptr;

	ft_memset(&ptr, 0, sizeof(t_ptr));
	ptr.check_type = 1;
	arg = va_arg(*p, wchar_t*);
	if (arg != NULL)
		ptr.nb = ft_strwlen(arg);
	else
		ptr.nb = 6;
	ptr.diff = ft_str_size(s, (void*)arg, ptr.check_type);
	ft_handle_str(s, (void*)arg, ptr.check_type);
	ptr.val = ptr.val + ft_size_chain_str_maj(s, ptr.nb, ptr.diff, arg);
	ptr.val = ptr.val + ft_size_chain_str_plus_maj(s, ptr.nb, ptr.diff, arg);
	if (ft_check_point(s) && ft_record_prec(s))
		return (ptr.val);
	return (ptr.val + ptr.nb);
}
