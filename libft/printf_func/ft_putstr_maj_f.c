/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/12 17:53:44 by hel-hadi         ###   ########.fr       */
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

int	ft_putstr_maj_f(va_list *p)
{
	ft_putstr_maj(va_arg(*p, wchar_t*));
	return (0);
}
