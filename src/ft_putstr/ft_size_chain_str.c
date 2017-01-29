/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_chain_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:05:20 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/29 16:23:00 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_size_chain_str_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	if (siz->nbr_prec < t_arg)
	{
		siz->ecart = siz->nbr_prec;
		siz->len = siz->len + (t_arg - siz->nbr_prec);
	}
	return (0);
}

int	ft_size_chain_str(char *s, int t_arg, int diff, char *arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.d = '0';
	if (ft_check_less(s))
		return (0);
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_str_bis(&siz, s, t_arg, diff);
	while (siz.i < siz.len)
	{
		ft_putchar(siz.d);
		siz.i++;
	}
	ft_putnstr(arg, siz.ecart);
	return (siz.i);
}

int	ft_size_chain_str_maj_bis(t_siz *siz, char *s, int t_arg, int diff)
{
	if (ft_check_zero(s) == 1)
		siz->d = '0';
	if (ft_check_zero(s) == 0)
		siz->d = ' ';
	if (siz->nbr_prec < t_arg &&  siz->nbr_prec)
	{
		siz->ecart = siz->nbr_prec;
		siz->len = siz->len + (t_arg - siz->nbr_prec);
	}
	return (0);
}

int	ft_size_chain_str_maj(char *s, int t_arg, int diff, wchar_t *arg)
{
	t_siz siz;

	ft_memset(&siz, 0, sizeof(t_siz));
	siz.nbr = ft_record_chain(s);
	siz.nbr_prec = ft_record_prec(s);
	siz.d = '0';
	if (ft_check_less(s))
		return (0);
	siz.len = siz.nbr - t_arg - diff;
	ft_size_chain_str_maj_bis(&siz, s, t_arg, diff);
	while (siz.i < siz.len)
	{
		ft_putchar(siz.d);
		siz.i++;
	}
	printf("%d\n", siz.ecart);
	ft_putnstr_maj(arg, siz.ecart);
	return (siz.i);
}

int	ft_size_chain_str_plus(char *s, int t_arg, int diff)
{
	int nbr;
	int i;
	int len;

	if (ft_check_less(s) == 0)
		return (0);
	nbr = ft_record_chain(s);
	i = 0;

	len = nbr - t_arg - diff;
	while (i < len)
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
