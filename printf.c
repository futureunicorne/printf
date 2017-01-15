/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/15 14:13:49 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_ptr_bis(char c, char d, char e)
{
	if (c == 'u')
		return (6);
	else if (c == 'o')
		return (7);
	else if (c == 'D')
		return (8);
	else if (c == 'X')
		return (9);
	else if (c == 'O')
		return (10);
	else if (c == 'U')
		return (11);
	else if (c == 'C')
		return (12);
	else if (c == 'S')
		return (13);
	else if (c == '%')
		return (14);
	return (0);
}

int	check_ptr(char c, char d, char e)
{
	if (c == 'l' && d =='l')
		e = e - 32;
	else if (c == 'l' && d != 'l')
		d = d - 32;
	if (c == 'c')
		return (1);
	else if (c == 'l')
		return (check_ptr(d, e, e));
	else if (c == 's')
		return (2);
	else if (c == 'd' || c == 'i')
		return (3);
	else if (c == 'p')
		return (4);
	else if (c == 'x')
		return (5);
	if (check_ptr_bis(c, d ,e))
		return (check_ptr_bis(c, d ,e));
	return (0);
}

void	ft_attribute_ptr(int (*ptr_func[])(va_list*))
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
	ptr_func[14] = &ft_empty_spec_f;
}

void	ft_resolve(char *s, t_pos *pos, va_list *ap, int(*ptr_func[])(va_list*))
{
	if (s[pos->i] == '%')
	{
		ft_putecart(s + pos->i + 1);
		if (ft_check_spec(s + pos->i + 1))
		{
			ptr_func[ft_check_spec(s + pos->i + 1)](ap);
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
		ft_putchar(s[pos->i]);
}

int	ft_printf(char *str, ...)
{
	t_pos pos;
	int (*ptr_func[15])(va_list *);
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
	return (0);
}

/*
int	ft_printf(char *str, ...)
{
	int i;
	int flag;
	int (*ptr_func[15])(va_list *);
	va_list ap;

	i = 0;
	flag = 0;
	ft_attribute_ptr(ptr_func);
	va_start(ap,str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_putecart(str + i + 1);
			if (ft_check_spec(str + i + 1))
			{
				ptr_func[ft_check_spec(str + i + 1)](&ap);
				if (ft_check_ecart(str + i + 1) > 0)
					i = i + ft_check_ecart(str + i + 1);
				if (str[i + 2] == 'l')
					i += 2;
				if (str[i + 1] == 'l')
					i += 2;
				else
					i++;;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	*/
