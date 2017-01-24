/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:17:50 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:37:58 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putspace_uns(int auth, int flag, int flag_z, int check_type)
{
   if (auth == 1 && flag == 0 && check_type == 0 && flag_z == 0)
	   ft_putchar(' ');
   else if (auth == 1 && flag == 0 && check_type == 0 && flag_z == 1)
	   ft_putchar(' ');
   return (0);
}
int ft_handle_uns(char *s, void *arg, int check_type)
{
   int i;
   t_pos pos;

   i = 0;
   ft_memset(&pos, 0, sizeof(t_pos));
   while (s[i] && check_ptr(s[i], s[i + 1],s[i + 2]) == 0)
   {
	   if (s[i] == '-' && pos.flag2 == 0)
	   {
		   pos.flag2 = 1;
		   pos.flag = 1;
	   }
	   else if (s[i] == ' ')
		   pos.auth = 1;
	   else if (s[i] == '0')
		   pos.flag_zero = 1;
	   i++;
   }
   if (ft_check_point(s) == 1)
	   check_type = 1;
   ft_putspace_uns(pos.auth, pos.flag, pos.flag_zero ,check_type);
   return (0);
}
