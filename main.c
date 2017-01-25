/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:27:15 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/25 09:46:53 by hel-hadi         ###   ########.fr       */
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
	unsigned int nb;

	c = 'c';
	s = "le gloububouka";
	nb = 15644975;
	setlocale(LC_ALL, "");
	ft_printf("%x", nb);
	printf("\n");
	setlocale(LC_ALL, "");
	printf("%x", nb);
	printf("\n");
	return (0);
}
//d ok
//x nok

/*
// type x est un unsigned
pour chaine de caracatere cela ninflue que sur la taille de la chaine,
le reste des des flag  reste inchanges

pour le numeriques, rajoute 0 pour completer la precision demandes, si la largeur de champs
est preciser et que l


*/
