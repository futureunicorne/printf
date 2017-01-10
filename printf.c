/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 17:22:28 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_flag(char c)
{
	if (c == 'c')
		return (0);
	else if (c == 's')
		return (1);
	else if (c == 'd' || c == 'i')
		return (2);
	else if (c == 'p')
		return (3);
	else if (c == 'x')
		return (4);
	else if (c == 'u')
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
	else if (c == 'O')
		return (11);
	else if (c == 'C')
		return (12);
	return (-1);
}

int	ft_printf(char *str, ...)
{
	int (*ptr_func[13])(va_list *);
	va_list ap;

	int i;
	int flag;
	// ajuster pour nouvelle fonction
	ptr_func[0] = &ft_putchar_f;  //valide
	ptr_func[1] = &ft_putstr_f;   // valide
	ptr_func[2] = &ft_putnbr_f;   // valid
	ptr_func[3] = &ft_putadd_f;   // valid
	ptr_func[4] = &ft_puthexa_f;  //valid mais check le 0
	ptr_func[5] = &ft_putuns_f;   //valid
	ptr_func[6] = &ft_putoctal_f; //valid
	ptr_func[7] = &ft_putnbr_big_f; //valid
	ptr_func[8] = &ft_puthexa_big_f; //valid
	ptr_func[9] = &ft_putoctal_big_f;
	//ptr_func[9] = &ft_putuns_big_f;b
	//ptr_func[12] = &ft_putchar_big_f;
	//ptr_func[10] = &ft_putstr_big_f;

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
