/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/13 17:40:25 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	wchar_t *str = {L"قد سعدت بالتحدث إليك قد سعدت بالتحدث إليك"};

	int i;
	i = 4294967;
	setlocale(LC_ALL, "");
	ft_printf("%S est hamza en arabe", str);
	ft_putchar('\n');
	setlocale(LC_ALL, "");
	printf("%S est hamza en arabe", str);
	return (0);
}
