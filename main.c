/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/11 17:45:38 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


int	main()
{
	wchar_t str[8] = {L"حمزة \n"};

	int i;
	i = 4294967;
	setlocale(LC_ALL, "");
	ft_printf("l adresse de str est %S", str);
	ft_putchar('\n');
	setlocale(LC_ALL, "");
	printf("l adresse de str est %S", str);
	return (0);
}
