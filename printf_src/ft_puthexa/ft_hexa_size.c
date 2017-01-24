/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:54:39 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:39:01 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putdieses_hexa(char *s)
{
	int i;
	int flag;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1],s[i + 2]);
	if (flag == 5)
		return (2);
	else if (flag == 7)
		return (1);
	else if (flag == 9)
		return (2);
	else if (flag == 10)
		return (1);
	return (0);
}

int	ft_putspace_hexa_bis(int auth, int flag, int flag_z, int check_type)
{
	if (auth == 1 && flag == 0  && check_type == 0 && flag_z == 0)
		return (1);
	if (auth == 1 && flag == 0  && check_type == 0 && flag_z == 1)
		return (1);
	return (0);
}

int ft_hexa_size(char *s, void *arg, int check_type)
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
		else if (s[i] == '#' && pos.flag3 == 0)
		{
			if (ft_putdieses_hexa(s) > 0)
				pos.flag_size = ft_putdieses_hexa(s);
			pos.flag3 = 1;
		}
		i++;
	}
	if (ft_check_point(s) == 1)
		check_type = 1;
	if (ft_putspace_hexa(pos.auth, pos.flag, pos.flag_zero, check_type) == 1)
		pos.flag_size++;
	return (pos.flag_size);
}
