/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_maj_f.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:09:26 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 07:02:14 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa_maj(int long n)
{
	int long nb;
	int long na;

	nb = n;
	na = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * (-1);
	}
	char *tab = "0123456789ABCDEF";
	if (nb >= 0 && nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa_maj(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 55);
		na = 0;
	}
}

int	ft_puthexa_maj_f(char *s, va_list *p)
{
	int 		arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, int long);
	nb = ft_strhlen((int long)arg);
	diff = ft_hexa_size(s, (void*)arg, check_type);
	ft_handle_hexa(s, (void*)arg, check_type);
	ft_size_chain_hexa_maj(s, nb, diff);
	ft_puthexa_maj(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
