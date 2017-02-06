/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 09:54:39 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 19:27:23 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putdieses_hexa(char *s)
{
	int i;
	int flag;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1], s[i + 2]) == 0)
		i++;
	flag = check_ptr(s[i], s[i + 1], s[i + 2]);
	if (flag == 5)
		return (2);
	else if (flag == 9)
		return (2);
	return (0);
}

int	ft_hexa_size(char *s, int arg, int check_type)
{
	int		i;
	t_pos	pos;

	i = 0;
	ft_memset(&pos, 0, sizeof(t_pos));
	while (s[i] && check_ptr(s[i], s[i + 1], s[i + 2]) == 0)
	{
		if (s[i] == '#' && pos.flag3 == 0)
		{
			if (ft_putdieses_hexa(s) > 0)
				pos.flag_size = ft_putdieses_hexa(s);
			pos.flag3 = 1;
		}
		i++;
	}
	return (pos.flag_size);
}
