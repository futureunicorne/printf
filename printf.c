/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 08:59:44 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_flag(char c)
{
	if (c == 'c')
		return (0);
	else if (c == 's')
		return (1);
	else if (c == 'd' || 'D')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'x' ||c == 'X')
		return (4);
	else
		printf ("option en cours ...\n ");
	return (-1);
}

int	ft_printf(char *str, ...)
{
	int (*ptr_func[5])(va_list *);
	va_list ap;

	int i;
	int flag;
	// ajuster pour nouvelle fonction
	ptr_func[0] = &ft_putchar_f;
	ptr_func[1] = &ft_putstr_f;
	ptr_func[2] = &ft_putnbr_f;
	ptr_func[3] = &ft_putadd_f;
	ptr_func[4] = &ft_puthexa_f;

	i = 0;
	flag = 0;
	va_start(ap,str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			flag = check_flag(str[i + 1]);
			ptr_func[flag](&ap);
			i++ ;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (0);
}
