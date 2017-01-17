/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/17 18:15:13 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	wchar_t *str = {L"Вы говорите по-русски? je sais pas"};

	int i;
	i = -575645;
	setlocale(LC_ALL, "");
	ft_printf("%10d\n", i);
	printf("%10d\n", i);
	setlocale(LC_ALL, "");
	//ft_printf("a%-dhamza\n", i);
	//printf("a%-dhamza\n", i);
	return (0);
}
