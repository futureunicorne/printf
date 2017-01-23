/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_prec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:18:13 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/23 15:10:52 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_handle_prec_nbr(char *s, int diff, )
{
	int nb_size;
	int nb_prec;
	char c;

	nb_size = ft_itoa(ft_record_prec(s));
	if (nb_prec > nb_size)
		c = '0';

}



char*	ft_record_prec(char *s)
{
	int i;
	int j;
	int flag;
	char *s1;

	i = 0;
	j = 0;
	flag = 0;
	s1 = ft_strnew(ft_strlen(s));
	while (s[i] && s[i] != '.')
		i++;
	while (s[i] && flag == 0)
	{
		while (s[i] >= '0' && s[i] <= '9')
		{
			s1[j] = s[i];
			j++;
			i++;
			flag = 1;
		}
		i++;
	}
	if (s1 == NULL)
		return (NULL);
	printf("%s\n", s1);
	return (s1);
}
