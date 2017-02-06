/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size_maj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:22:03 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 19:01:31 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_putplus_nbr_bis_maj(char *s, ssize_t arg)
{
	int i;
	int flag;
	int nb;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1], s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1], s[i + 2]);
	if (arg >= 0 && (flag == 3 || flag == 8))
		return (1);
	return (0);
}

int		ft_putspace_nbr_bis_maj(int auth, int flag, int flag_z, int check_type)
{
	if (auth == 1 && flag == 0 && check_type == 0 && flag_z == 0)
		return (1);
	if (auth == 1 && flag == 0 && check_type == 0 && flag_z == 1)
		return (1);
	return (0);
}

void	ft_nbr_size_maj1(char *s, int long arg, int check_type, t_pos *pos)
{
	if (s[pos->i] == '-' && pos->flag2 == 0)
	{
		pos->flag2 = 1;
		pos->flag = 1;
	}
	else if (s[pos->i] == '+' && pos->flag1 == 0)
	{
		if (ft_putplus_nbr_bis_maj(s, arg) == 1)
			pos->flag_size++;
		pos->flag1 = 1;
		pos->flag = 1;
	}
	else if (s[pos->i] == ' ')
		pos->auth = 1;
	else if (s[pos->i] == '0')
		pos->flag_zero = 1;
}

int		ft_nbr_size_maj(char *s, int long arg, int check_type)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	while (s[pos.i] && check_ptr(s[pos.i], s[pos.i + 1], s[pos.i + 2]) == 0)
	{
		ft_nbr_size_maj1(s, arg, check_type, &pos);
		pos.i++;
	}
	if (ft_check_point(s) == 1)
		check_type = 1;
	if (ft_putspace_nbr_bis_maj(pos.auth, pos.flag, pos.flag_zero, check_type)
	== 1)
		pos.flag_size++;
	return (pos.flag_size);
}
