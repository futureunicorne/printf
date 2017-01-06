/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/06 17:45:54 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int     check_flag(char c)
{
  if (c == 'c')
    return (0);
  else if (c == 's')
    return (1);
  else if (c == 'd')
    return (2);
  else
    printf ("option en cours ...\n ");
  return (-1);
}

int     ft_printf(char *str, ...)
{
	int (*ptr_func[3])(va_list *);
 	va_list ap;

	int i;
	int flag;
	ptr_func[0] = &my_putchar_v;
	ptr_func[1] = &my_putstr_v;
	ptr_func[2] = &my_put_nbr_v;
	i = 0;
	flag = 0;
	va_start(ap,str);
	while (str[i] != '\0')
	{
      if (str[i] == '%')
	  {
          flag = check_flag(str[i+1]);
          ptr_func[flag](&ap);
	  }
      else
        ft_putchar(str[i]);
      i++;
    }
  va_end(ap);
  return (0);
}

/* juste les fonctions basiques qui affichent int , char et string */
int     my_putchar_v(va_list *p)
{
  ft_putchar((char) va_arg(p,int ));
  return (0);
}


int     my_putstr_v(va_list *p)
{
  my_putstr(va_arg(p,char *));
  return (0);
}


int     ft_put_nbr_v(va_list *p)
{
  my_put_nbr(va_arg(p, int));
  return (0);
}
