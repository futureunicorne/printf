/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/26 18:53:49 by hel-hadi         ###   ########.fr       */
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
	unsigned nb;

	c = 'c';
	s = "le gloububouka";
	nb = 1;
	setlocale(LC_ALL, "");
	ft_printf("%0+5d", -42);
	printf("\n");
	setlocale(LC_ALL, "");
	printf("%0+5d", -42);
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

