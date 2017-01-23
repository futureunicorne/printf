/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:16:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/23 17:28:15 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "../../printf.h"

int	ft_putplus(char *s, void *arg)
{
	int i;
	int flag;
	int nb;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1],s[i + 2]);
	if (((long)arg > 2147483647 || (long)arg < 0) && flag == 3)
		return (0);
	if (arg >= 0 && (flag == 3 || flag == 8))
		return (1);
	return (0);
}


int	ft_putspace(int auth, int flag, int flag_z, int check_type)
{
	if (auth == 1 && flag == 0 && check_type == 0 && flag_z == 0)
		ft_putchar(' ');
	else if (auth == 1 && flag == 0 && check_type == 0 && flag_z == 1)
		ft_putchar(' ');
	return (0);
}
int ft_handle_hexa(char *s, void *arg, int check_type)
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
		else if (s[i] == '+' && pos.flag1 == 0)
		{
			ft_putplus(s, arg);
			pos.flag1 = 1;
			pos.flag = 1;
		}
		else if (s[i] == ' ')
			pos.auth = 1;
		else if (s[i] == '0')
			pos.flag_zero = 1;
		else if (s[i] == '#' && pos.flag3 == 0)
		{
			pos.flag3 = 1;
			pos.flag = 1;
		}
		i++;
	}
	if (ft_check_point(s) == 1)
		check_type = 1;
	ft_putspace(pos.auth, pos.flag, pos.flag_zero ,check_type);
	return (0);
}
