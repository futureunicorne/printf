/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_spec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:37:05 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 12:11:17 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_ptr_bis2(char c)
{
	if (c == 'u')
		return (6);
	else if (c == 'o')
		return (7);
	else if (c == 'D')
		return (8);
	else if (c == 'X')
		return (9);
	else if (c == 'O')
		return (10);
	else if (c == 'U')
		return (11);
	else if (c == 'C')
		return (12);
	else if (c == 'S')
		return (13);
	else if (c == '%')
		return (14);
	return (0);
}

int	check_ptr2(char c)
{
	if (c == 'c')
		return (1);
	else if (c == 's')
		return (2);
	else if (c == 'd' || c == 'i')
		return (3);
	else if (c == 'p')
		return (4);
	else if (c == 'x')
		return (5);
	if (check_ptr_bis2(c))
		return (check_ptr_bis2(c));
	return (0);
}

int	check_ptr_bis(char c, char d, char e)
{
	if (c == 'u')
		return (6);
	else if (c == 'o')
		return (7);
	else if (c == 'D')
		return (8);
	else if (c == 'X')
		return (9);
	else if (c == 'O')
		return (10);
	else if (c == 'U')
		return (11);
	else if (c == 'C')
		return (12);
	else if (c == 'S')
		return (13);
	else if (c == '%')
		return (14);
	return (0);
}

int	check_ptr(char c, char d, char e)
{
	if (c == 'c')
		return (1);
	else if (c == 'l')
		return (check_ptr(d, e, e));
	else if (c == 's')
		return (2);
	else if (c == 'd' || c == 'i')
		return (3);
	else if (c == 'p')
		return (4);
	else if (c == 'x')
		return (5);
	if (check_ptr_bis(c, d ,e))
		return (check_ptr_bis(c, d ,e));
	return (0);
}

char	*ft_return_chain(char *s)
{
	int i;
	char *s1;

	i = 1;
	while (s[i] && (!check_ptr2(s[i])))
		i++;
	if (check_ptr(s[i], s[i + 1],s[i + 2]))
	{
		s1 = ft_strsub(s, 1, i);
		return (s1);
	}
	return (NULL);
}

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
