/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/18 15:03:39 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_f(char *s, va_list *p)
{
	char	*arg;
	int		nb;
	int		diff;

	nb = 0;
	diff = 0;
	arg = va_arg(*p, char*);
	nb = ft_strlen(arg);
	diff = ft_flag_size(s,(void*)arg);
	ft_size_chain(s, nb, diff);
	ft_handle_flag(s, arg);
	ft_putstr(arg);
	return (0);
}
