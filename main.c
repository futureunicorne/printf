/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:01:42 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_src/printf.h"

int	main()
{
	wchar_t *str = {L"C Pождеством Xристовом"};
	wchar_t cs = {L'🕦'};
	char *s;
	char c;
	int	nb;

	c = 'c';
	s = "le gloububouka";
	nb = 1564435;
	setlocale(LC_ALL, "");
	ft_printf("% +   -#15ld", nb);
	printf("\n");
	setlocale(LC_ALL, "");
	printf("% +   -#15ld", nb);
	printf("\n");
	return (0);
}
//d ok
//x nok

/*

pour chaine de caracatere cela ninflue que sur la taille de la chaine,
le reste des des flag  reste inchanges

pour le numeriques, rajoute 0 pour completer la precision demandes, si la largeur de champs
est preciser et que l


*/
