/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_maj_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:07:06 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/11 15:53:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putstr_maj(wchar_t *s)
{
	if (s)
		write(1, s, ft_strlen((const char *)s));
}

int	ft_putstr_maj_f(va_list *p)
{
	ft_putstr_maj(va_arg(*p, wchar_t*));
	return (0);
}
