/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:24:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:22:48 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puthexa(int long n)
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
	if (nb >= 1)
	{
		ft_puthexa(nb / 16);
		na = nb % 16;
		if (na + 48 >= '0' && na + 48 <= '9')
			ft_putchar(na + 48);
		else
			ft_putchar(na + 87);
		na = 0;
	}
}

int	ft_puthexa_f(char *s, va_list *p)
{
	int long	arg;
	int			nb;
	int			diff;

	arg = va_arg(*p, int long);
	nb = ft_count_num((int long)arg) - 1;
	diff = ft_flag_size(s, (void*)arg);
	printf("%d\n",nb);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_puthexa(arg);
	return (0);
}
