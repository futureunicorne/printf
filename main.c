/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/06 15:00:25 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include "libft/libft.h"

int	main()
{
	wchar_t *str = {L"C Pождествоfdfgfgbм Xристовом"};
	wchar_t cs = {L'🕦'};
	char *s;
	char c;
	int nb;
	unsigned test_simple_mix;

	test_simple_mix = 0;
	c = 'c';
	s = "le gloububouka";
	nb = 0;
	setlocale(LC_ALL, "");
	ft_printf("s: %s, p: %p, d:%d", "a string", &nb, 42);
	printf("\n");
	setlocale(LC_NUMERIC, "");
 	printf("\nvap = %d\n", printf("s: %s, p: %p, d:%d", "a string", &nb, 42));
	return (0);
}
//d ok
//x nok

/*
// type x est un unsigned
pour chaine de caracatere cela ninflue que sur la taille d e la chaine,
le reste des des flag  reste inchanges
gerer % + d +%

#ifndef BUILTIN
	(void) setlocale(LC_NUMERIC, "");

pour le numeriques, rajoute 0 pour completer la precision demandes, si la largeur de champs
est preciser et que l

printf("oui\n");
*/
