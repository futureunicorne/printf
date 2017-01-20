/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:47:11 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa(int long nb)
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
	int long	arg;
	int			nb;
	int			diff;
	int			check_type;

	check_type = 0;
	arg = va_arg(*p, int long);
	nb = ft_count_num((int long)arg) - 1;
	diff = ft_flag_size(s, (void*)arg);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_puthexa(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
