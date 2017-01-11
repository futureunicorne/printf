/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:11 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/10 20:51:19 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int ft_printf(char *str, ...);
int	check_flag(char c, char d, char e);



#endif
