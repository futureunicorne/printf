/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/12 21:34:51 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	wchar_t str = {54775};

	int i;
	i = 4294967;
	setlocale(LC_ALL, "");
	ft_printf("%C est hamza en arabe", str);
	ft_putchar('\n');
	setlocale(LC_ALL, "");
	printf("%C est hamza en arabe", str);
	return (0);
}
