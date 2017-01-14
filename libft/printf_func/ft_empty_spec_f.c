/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_spec_f.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 15:58:18 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/14 17:26:53 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_empty_spec(char *str)
{
	ft_putstr("");
}

int	ft_empty_spec_f(va_list *p)
{
	ft_empty_spec(va_arg(*p, char*));
	return (0);
}
