/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:01:12 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/31 19:00:13 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putdieses_oct(char *s)
{
	int i;
	int flag;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1],s[i + 2]);

	if (flag == 7)
		return (1);
	else if (flag == 10)
		return (1);
	return (0);
}

int ft_oct_size(char *s, int check_type)
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
		else if (s[i] == '0')
			pos.flag_zero = 1;
		else if (s[i] == '#' && pos.flag3 == 0)
		{
			if (ft_putdieses_oct(s) > 0)
				pos.flag_size = ft_putdieses_oct(s);
			pos.flag3 = 1;
		}
		i++;
	}

	return (pos.flag_size);
}
