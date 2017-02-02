/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:00 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/02 18:09:50 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_letter(char *s, char spec)
{
	int i;
	int auth;
	int flag;

	i = 0;
	auth = 0;
	flag = 0;
	printf("%s\n",s );
	while (s[i])
	{
		if (check_ptr2(s[i]))
		{
			auth = check_ptr2(s[i]);
			if (check_ptr2(s[i]) == auth && flag == 1)
				return (1);
			flag = 1;
		}
		i++;
	}
	return (0);
}
