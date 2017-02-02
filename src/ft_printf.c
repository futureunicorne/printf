/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/02 21:08:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_attribute_ptr(int (*ptr_func[])(char * s, va_list*))
{
	ptr_func[1]  = &ft_putchar_f;
	ptr_func[2]  = &ft_putstr_f;
	ptr_func[3]  = &ft_putnbr_f;
	ptr_func[4]  = &ft_putadd_f;
	ptr_func[5]  = &ft_puthexa_f;
	ptr_func[6]  = &ft_putuns_f;
	ptr_func[7]  = &ft_putoctal_f;
	ptr_func[8]  = &ft_putnbr_maj_f;
	ptr_func[9]  = &ft_puthexa_maj_f;
	ptr_func[10]  = &ft_putoctal_maj_f;
	ptr_func[11] = &ft_putuns_maj_f;
	ptr_func[12] = &ft_putchar_maj_f;
	ptr_func[13] = &ft_putstr_maj_f;
	ptr_func[14] = &ft_putpercent_f;
}

void	ft_resolve(char *s, t_pos *pos, va_list *ap, int(*ptr_func[])(char *s, va_list*))
{
	char *spec;

	if (s[pos->i] == '%')
	{
		if (ft_check_spec(s + pos->i + 1))
		{
			spec = ft_return_chain(s + pos->i);
			pos->val = pos->val + ptr_func[ft_check_spec(spec)](spec, ap);
			if (ft_check_ecart(s + pos->i + 1) > 0)
				pos->i = pos->i + ft_check_ecart(s + pos->i + 1);
			if (s[pos->i + 2] == 'l')
				pos->i += 2;
			if (s[pos->i + 1] == 'l')
				pos->i += 2;
			else
				pos->i++;
		}
	}
	else
	{
		ft_putchar(s[pos->i]);
		pos->val++;
	}
}

int	ft_printf(char *str, ...)
{
	t_pos pos;
	int (*ptr_func[15])(char*, va_list*);
	va_list ap;

	ft_memset(&pos, 0, sizeof(t_pos));
	ft_attribute_ptr(ptr_func);
	va_start(ap,str);
	while (str[pos.i])
	{
		ft_resolve(str, &pos, &ap, ptr_func);
		pos.i++;
	}
  	va_end(ap);
	printf("\nval = %d\n",pos.val);
	return (pos.val);
}
