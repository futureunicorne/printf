/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/28 19:28:55 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include "libft/libft.h"

int	main()
{
	wchar_t *str = {L"C Pождеством Xристовом"};
	wchar_t cs = {L'🕦'};
	char *s;
	char c;
	int nb;

	c = 'c';
	s = "le gloububouka";
	nb = 327611;
	setlocale(LC_ALL, "");
	ft_printf("%-#18.18x", nb);
	printf("\n");
	setlocale(LC_ALL, "");
	printf("%-#18.18x", nb);
	printf("\n");
	return (0);
}
//d ok
//x nok

/*
// type x est un unsigned
pour chaine de caracatere cela ninflue que sur la taille de la chaine,
le reste des des flag  reste inchanges
gerer % + d +%

pour le numeriques, rajoute 0 pour completer la precision demandes, si la largeur de champs
est preciser et que l

printf("oui\n");
*/
