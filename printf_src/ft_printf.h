/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:00:17 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/01/24 17:48:05 by hel-hadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdio.h>
# include <wctype.h>
# include <locale.h>
# include "../libft/libft.h"

void	ft_attribute_ptr(int (*ptr_func[])(char * s, va_list*));
int		ft_printf(char *str, ...);
int		ft_record_prec(char *s);
int		ft_record_chain(char *s);
int		ft_check_point(char *s);
int		ft_check_less(char *s);
int		ft_check_more(char *s);
int		ft_check_space(char *s);
int		ft_check_dieses(char *s);
int		ft_check_zero(char *s, int nb);
int		check_ptr_bis(char c, char d, char e);
int		check_ptr(char c, char d, char e);
int		ft_check_spec(char *s);
int		ft_check_ecart(char *s);
int		ft_putspace_uns(int auth, int flag, int flag_z, int check_type);
int		ft_handle_uns(char *s, void *arg, int check_type);
void	ft_putuns(unsigned n);
int		ft_putuns_f(char *s, va_list *p);
void	ft_putuns_maj(unsigned long long n);
int		ft_putuns_maj_f(char *s, va_list *p);
int		ft_size_chain_uns_plus(char *s, int t_arg, int diff);
int		ft_size_chain_uns(char *s, int t_arg, int diff);
int		ft_putspace_uns_bis(int auth, int flag, int flag_z, int check_type);
int		ft_uns_size(char *s, void *arg, int check_type);
int		ft_putspace_str(int auth, int flag, int flag_z, int check_type);
int 	ft_handle_str(char *s, void *arg, int check_type);
int		ft_putstr_f(char *s, va_list *p);
int		ft_strwlen(wchar_t *s);
void	ft_putstr_maj(wchar_t *s);
int		ft_putstr_maj_f(char *s, va_list *p);
int		ft_size_chain_str_plus(char *s, int t_arg, int diff);
int		ft_size_chain_str(char *s, int t_arg, int diff);
int		ft_putspace_str_bis(int auth, int flag, int flag_z, int check_type);
int 	ft_str_size(char *s, void *arg, int check_type);
void 	ft_putpercent(char *str);
int		ft_putpercent_f(char *s, va_list *p);
int		ft_putspace_oct(int auth, int flag, int flag_z, int check_type);
int 	ft_handle_oct(char *s, void *arg, int check_type);
int		ft_putdieses_oct(char *s);
int		ft_putspace_oct_bis(int auth, int flag, int flag_z, int check_type);
int 	ft_oct_size(char *s, void *arg, int check_type);
int		ft_nbr_octal_len(int long nb);
void	ft_putoctal(int long n);
int		ft_putoctal_f(char *s, va_list *p);
void	ft_putoctal_maj(long long n);
int		ft_putoctal_maj_f(char *s ,va_list *p);
int		ft_size_chain_oct(char *s, int t_arg, int diff);
int		ft_size_chain_oct_plus(char *s, int t_arg, int diff);
int		ft_putplus_nbr(char *s, void *arg);
int		ft_putspace_nbr(int auth, int flag, int flag_z, int check_type);
int		ft_putplus_nbr_bis(char *s, void *arg);
int		ft_putdieses_nbr_bis(char *s);
int		ft_putspace_bis(int auth, int flag, int flag_z, int check_type);
int 	ft_nbr_size(char *s, void *arg, int check_type);
void	ft_putnbr_maj(int long n);
int		ft_putnbr_maj_f(char *s, va_list *p);
int		ft_putnbr_f(char *s, va_list *p);
int		ft_size_chain_nbr(char *s, int t_arg, int diff);
int		ft_size_chain_nbr_plus(char *s, int t_arg, int diff);
int		ft_putspace_hexa(int auth, int flag, int flag_z, int check_type);
int 	ft_handle_hexa(char *s, void *arg, int check_type);
int		ft_putdieses_hexa(char *s);
int		ft_putspace_hexa_bis(int auth, int flag, int flag_z, int check_type);
int 	ft_hexa_size(char *s, void *arg, int check_type);
int		ft_strhlen(int nb);
void	ft_puthexa(int nb);
int		ft_puthexa_f(char *s, va_list *p);
void	ft_puthexa_maj(int long n);
int		ft_puthexa_maj_f(char *s, va_list *p);
int		ft_size_chain_hexa(char *s, int t_arg, int diff);
int		ft_size_chain_hexa_maj(char *s, int t_arg, int diff);
int		ft_size_chain_hexa_plus(char *s, int t_arg, int diff);
int		ft_putspace_char(int auth, int flag, int flag_z, int check_type);
int 	ft_char_size(char *s, void *arg, int check_type);
int		ft_putspace_char_bis(int auth, int flag, int flag_z, int check_type);
int		ft_handle_char(char *s, void *arg, int check_type);
int		ft_putchar_f(char *s, va_list *p);
int		ft_strwclen(wchar_t arg);
void	ft_putchar_maj(wchar_t c);
int		ft_putchar_maj_f(char *s, va_list *p);
int		ft_size_chain_char(char *s, int t_arg, int diff);
int		ft_size_chain_char_plus(char *s, int t_arg, int diff);
int		ft_putspace_add(int auth, int flag, int flag_z, int check_type);
int 	ft_add_size(char *s, void *arg, int check_type);
int		ft_putspace_add_bis(int auth, int flag, int flag_z, int check_type);
int 	ft_handle_nbr(char *s, void *arg, int check_type);
int		ft_nbr_add_len(int long nb);
void	ft_putadd(int long nb);
int		ft_putadd_f(char *s, va_list *p);
int		ft_size_chain_add_plus(char *s, int t_arg, int diff);
int		ft_size_chain_add(char *s, int t_arg, int diff);

typedef struct	s_pos
{
	int			i;
	int			flag;
	int			auth;
	int			flag1;
	int			flag2;
	int			flag3;
	int			flag_size;
	int			flag_zero;
}				t_pos;

#endif
