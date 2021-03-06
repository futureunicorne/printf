/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:57:31 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/08 11:04:20 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putplus_nbr_bis(char *s, ssize_t arg)
{
	int i;
	int flag;
	int nb;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr2(s[i]) == 0)
		i++;
	flag = check_ptr2(s[i]);
	if (arg >= 0 && (flag == 3 || flag == 8))
		return (1);
	return (0);
}

int	ft_putspace_nbr_bis(int auth, int flag, int flag_z)
{
	if (auth == 1 && flag == 0 && flag_z == 1)
		return (1);
	return (0);
}

int	ft_nbr_size(char *s, int arg)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (s[pos.i] && check_ptr2(s[pos.i]) == 0)
	{
		if (s[pos.i] == '-' && pos.flag2 == 0)
			pos.flag2 = 1;
		else if (s[pos.i] == '+' && pos.flag1 == 0)
		{
			if (ft_putplus_nbr_bis(s, arg) == 1)
				pos.flag_size++;
			pos.flag1 = 1;
			pos.flag = 1;
		}
		else if (s[pos.i] == ' ')
			pos.auth = 1;
		else if (s[pos.i] == '0')
			pos.flag_zero = 1;
		pos.i++;
	}
	if (ft_putspace_nbr_bis(pos.auth, pos.flag, pos.flag_zero) == 1)
		pos.flag_size++;
	return (pos.flag_size);
}
