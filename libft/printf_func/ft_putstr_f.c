/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:13:38 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 18:48:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstr_f(char *s, va_list *p)
{
	char	*arg;
	int		nb;
	int		diff;
	int		check_type;

	nb = 0;
	diff = 0;
	check_type = 1;
	arg = va_arg(*p, char*);
	nb = ft_strlen(arg);
	diff = ft_flag_size(s,(void*)arg);
	ft_handle_flag(s, arg, check_type);
	ft_size_chain(s, nb, diff);
	ft_putstr(arg);
	ft_size_chain_plus(s, nb, diff);
	return (0);
}
