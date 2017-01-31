/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:49:39 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/31 10:43:14 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int ft_handle_add(char *s, int long arg, int check_type)
{
	int i;
	t_pos pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == '-' && pos.flag2 == 0)
		{
			pos.flag2 = 1;
			pos.flag = 1;
		}
		else if (s[i] == ' ')
			pos.auth = 1;
		else if (s[i] == '0')
			pos.flag_zero = 1;
		i++;
	}
	if (ft_check_point(s) == 1)
		check_type = 1;
 	return (0);
}
