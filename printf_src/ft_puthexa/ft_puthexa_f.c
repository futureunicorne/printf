/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 07:01:35 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strhlen(int nb)
{
	int i;

	i = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

void	ft_puthexa(int nb)
{
	char *tab = "0123456789abcdef";
	if (nb >= 0 && nb <= 15)
		ft_putchar(tab[nb]);
	if (nb >= 16)
	{
		ft_puthexa(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}


int	ft_puthexa_f(char *s, va_list *p)
{
	int			arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 1;
	arg = va_arg(*p, int);
	nb = ft_strhlen((int)arg);
	diff = ft_hexa_size(s, (void*)arg, check_type);
	ft_handle_hexa(s, (void*)arg, check_type);
	ft_size_chain_hexa(s, nb, diff);
	ft_puthexa(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
