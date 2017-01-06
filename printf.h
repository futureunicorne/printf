/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:06:11 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/06 10:50:34 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int	printf (const char *format, ...);

#endif