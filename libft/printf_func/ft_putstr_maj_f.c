/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:11:58 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_maj(wchar_t *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar_maj(s[i]);
		i++;
	}
}

int	ft_putstr_maj_f(char *s, va_list *p)
{
	wchar_t *arg;
	int		nb;
	int		diff;

	nb = 0;
	diff = 0;
	arg = va_arg(*p, wchar_t*);
	nb = ft_strlen((const char*)arg);
	diff = ft_flag_size(s, (void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, (void*)arg);
	ft_putstr_maj(arg);
	return (0);
}
