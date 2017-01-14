/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/14 17:26:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_flag_bis(char c, char d, char e)
{
	if (c == 'u')
		return (5);
	else if (c == 'o')
		return (6);
	else if (c == 'D')
		return (7);
	else if (c == 'X')
		return (8);
	else if (c == 'O')
		return (9);
	else if (c == 'U')
		return (10);
	else if (c == 'C')
		return (11);
	else if (c == 'S')
		return (12);
	else if (c == '\0')
		return (13);
	return (-1);
}

int	check_flag(char c, char d, char e)
{
	if (c == 'c')
		return (0);
	else if (c == 'l')
		return (check_flag(d, e, e));
	else if (c == 's')
		return (1);
	else if (c == 'd' || c == 'i')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'x')
		return (4);
	if (check_flag_bis(c, d ,e))
		return (check_flag_bis(c, d ,e));
	return (-1);
}

void	ft_attribute_ptr(int (*ptr_func[])(va_list*))
{
	ptr_func[0]  = &ft_putchar_f;
	ptr_func[1]  = &ft_putstr_f;
	ptr_func[2]  = &ft_putnbr_f;
	ptr_func[3]  = &ft_putadd_f;
	ptr_func[4]  = &ft_puthexa_f;
	ptr_func[5]  = &ft_putuns_f;
	ptr_func[6]  = &ft_putoctal_f;
	ptr_func[7]  = &ft_putnbr_maj_f;
	ptr_func[8]  = &ft_puthexa_maj_f;
	ptr_func[9]  = &ft_putoctal_maj_f;
	ptr_func[10] = &ft_putuns_maj_f;
	ptr_func[11] = &ft_putchar_maj_f;
	ptr_func[12] = &ft_putstr_maj_f;
	ptr_func[13] = &ft_empty_spec_f;
}

int	ft_printf(char *str, ...)
{
	int i;
	int flag;
	int (*ptr_func[14])(va_list *);
	va_list ap;

	i = 0;
	flag = 0;
	ft_attribute_ptr(ptr_func);
	va_start(ap,str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
			{
				ft_putchar(str[i]);
				i++;
			}
			else
			{
				flag = check_flag(str[i + 1], str[i + 2], str[i + 3]);
				ptr_func[flag](&ap);
				if (str[i + 2] == 'l')
					i += 2;
				if (str[i + 1] == 'l')
					i += 2;
				else
					i++;
			}
		}
		else
			ft_putchar(str[i]);
		i++;
	}
  	va_end(ap);
	return (0);
}
