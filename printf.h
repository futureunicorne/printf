/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:11 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/20 10:49:02 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <wctype.h>
# include <locale.h>

int ft_printf(char *str, ...);
int	check_flag(char c, char d, char e);

typedef	struct		s_pos
{
	int				i;
	int				flag;
	int				auth;
	int				flag1;
	int				flag2;
	int				flag3;
	int				flag_size;
	int				flag_zero;
}					t_pos;


#endif
