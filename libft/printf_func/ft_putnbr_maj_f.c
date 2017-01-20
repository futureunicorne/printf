/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:41 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/20 18:27:36 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr_maj(int long n)
{

	long long nb;
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
		ft_putnbr_maj(nb / 10);
		ft_putchar((nb % 10) + 48);
	}
}

int	ft_putnbr_maj_f(char *s, va_list *p)
{
	int long 	arg;
	int 		nb;
	int			diff;
	int			len;
	int			check_type;

	check_type = 0;
	arg = va_arg(*p, int long);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg, check_type);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain_base(s, nb, diff, '+');
	ft_putnbr_maj(arg);
	ft_size_chain_plus_base(s, nb, diff);
	return (0);
}

int	ft_putnbr_f(char *s, va_list *p)
{
	int arg;
	int nb;
	int diff;
	int	check_type;


	diff = 0;
	check_type = 0;
	arg = va_arg(*p, int);
	nb = ft_count_num((int long)arg);
	diff = ft_flag_size(s, (void*)arg, check_type);
	ft_handle_flag(s, (void*)arg, check_type);
	ft_size_chain_base(s, nb, diff, '+');
	ft_putnbr(arg);
	ft_size_chain_plus_base(s, nb, diff);
	return (0);
}
