/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/15 14:08:56 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	main()
{
	wchar_t *str = {L"Вы говорите по-русски? je sais pas"};

	int i;
	i = 5;
	setlocale(LC_ALL, "");
	ft_printf("% d je ne\n", -14521452);
	printf("% d je ne\n", -14521452);
	setlocale(LC_ALL, "");
	//ft_printf("a%-dhamza\n", i);
	//printf("a%-dhamza\n", i);
	return (0);
}
