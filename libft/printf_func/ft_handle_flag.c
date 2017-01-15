/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:46:37 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/15 14:13:44 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

// mettrelachaine de caractere dans une liste chaines
/* les espaces */

int	ft_putspace(char *s)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
	{
		if (s[i] == ' ' && flag == 0)
		{
			ft_putchar(' ');
			flag = 1;
		}
		i++;
	}
	return (i);
}

/* le plus et le moins */

/* le dieses */
