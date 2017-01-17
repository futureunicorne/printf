/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/17 16:20:21 by hel-hadi         ###   ########.fr       */
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

	arg = va_arg(*p, wchar_t*);
	ft_handle_flag(s, (void*)arg);
	ft_putstr_maj(arg);
	return (0);
}
