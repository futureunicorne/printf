/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:37:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/15 14:13:45 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_check_spec(char *s)
{
	int i;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	if (check_ptr(s[i], s[i + 1],s[i + 2]))
		return (check_ptr(s[i], s[i + 1],s[i + 2]));
	return (0);
}

int	ft_check_ecart(char *s)
{
	int i;

	i = 0;
	while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
		i++;
	return (i);
}

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





/*
int i;
int flag;
int auth;

i = 0;
auth = 0;
flag = 0;
while (str[i] && i <=  pos)
{
	if (str[i] == '%' && auth == 0)
		auth++;
	if (str[i] == '%' && auth == 1)
		auth--;
	i++;
}
return (auth);
*/
