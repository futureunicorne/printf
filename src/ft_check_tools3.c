/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/02 18:21:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_letter(char *s, char c)
{
	int i;
	int auth;

	i = 0;
	auth = 0;
	while (s[i])
	{
		if (s[i] == c)
			auth++;
		i++;
	}
	if (auth > 1)
		return (1);
	return (0);
}
