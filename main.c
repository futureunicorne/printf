/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/19 19:01:38 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	wchar_t *str = {L"C Pождеством Xристовом"};
	wchar_t cs = {L'д'};
	char *s;
	char c;
	int	nb;

	c = 'c';
	s = "le gloububouka";
	nb = 1564435;
	setlocale(LC_ALL, "");
	ft_printf("%p", nb);
	printf("\n");
	setlocale(LC_ALL, "");
	printf("%p", nb);
	return (0);
}
