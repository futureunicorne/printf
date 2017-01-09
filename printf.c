/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:08 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/09 10:07:36 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	int long nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + 48);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int     ft_putchar_f(va_list *p)
{
	ft_putchar((char) va_arg(p,int ));
	return (0);
}

int     ft_putstr_f(va_list *p)
{
  ft_putstr(va_arg(p,char *));
  return (0);
}

int		ft_putnbr_f(va_list *p)
{
  ft_putnbr(va_arg(p, int));
  return (0);
}

int     check_flag(char c)
{
  if (c == 'c')
    return (1);
  else if (c == 's')
    return (2);
  else if (c == 'd')
    return (3);
  else
    printf ("option en cours ...\n ");
  return (0);
}

int     ft_printf(char *str, ...)
{
	int (*ptr_func[3])(va_list *);
 	va_list ap;

	int i;
	int flag;
	// qualification of function punters
	ptr_func[1] = &ft_putchar_f;
	ptr_func[2] = &ft_putstr_f;
	ptr_func[3] = &ft_putnbr_f;
	ptr_func[4] = &ft_putadd_f;
	i = 0;
	flag = 0;
	va_start(ap,str);
	while (str[i] != '\0')
	{
      if (str[i] == '%')
	  {
          flag = check_flag(str[i + 1]);
          ptr_func[flag](&ap);
		  i++;
	  }
      else
        ft_putchar(str[i]);
      i++;
    }
  va_end(ap);
  return (0);
}

int	main()
{
	char *str;

	str = "et demi";
	ft_printf("hamza a %d ans %s", 5, str);

	//printf("je ne sais pas ce que sa %%\n donnes");
	return (0);
}