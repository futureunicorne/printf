/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hadi <hel-hadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:00:17 by hel-hadi          #+#    #+#             */
/*   Updated: 2017/02/08 11:53:04 by hel-hadi         ###   ########.fr       */
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
# include <inttypes.h>
# include <limits.h>
# include "libft/libft.h"

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
	int			val;
	char		*spec;
}				t_pos;

typedef struct	s_siz
{
	int			i;
	int			flag;
	int			val;
	int			cpt;
	int			flag_plus;
	int			nbr;
	int			nbr_prec;
	int			len;
	int			ecart;
	char		d;
	char		e;
	int			res;
}				t_siz;

typedef struct	s_ptr
{
	int			nb;
	int			val;
	int			diff;
	int			flag;
	int			check_type;
}				t_ptr;

typedef struct	s_chk
{
	int			i;
	int			j;
	int			res;
	int			flag;
	char		*s1;
}				t_chk;

typedef struct	s_wch
{
	wchar_t		c;
	wchar_t		d;
	wchar_t		e;
}				t_wch;

int				ft_printf(char *str, ...);
void			ft_attribute_ptr(int (*ptr_func[])(char *s, va_list*));
void			ft_resolve(char *s, t_pos *pos,
				va_list *ap, int(*ptr_func[])(char *s, va_list*));
void			ft_attribute_ptr(int (*ptr_func[])(char *s, va_list*));
int				ft_check_letter(char *s, char c);
int				ft_record_prec(char *s);
int				ft_record_chain(char *s);
int				ft_check_point(char *s);
int				ft_check_long(char *s);
int				ft_check_less(char *s);
int				ft_check_more(char *s);
int				ft_check_space(char *s);
int				ft_check_dieses(char *s);
int				ft_check_zero(char *s);
int				check_ptr_bis2(char c);
int				check_ptr2(char c);
char			*ft_return_chain(char *s);
int				ft_check_spec(char *s);
int				ft_check_ecart(char *s);
int				ft_putuns_f(char *s, va_list *p);
int				ft_putuns_z(char *s, va_list *p);
int				ft_putuns_j(char *s, va_list *p);
int				ft_putuns_h(char *s, va_list *p);
int				ft_putuns_hh(char *s, va_list *p);
int				ft_putuns_maj_f(char *s, va_list *p);
void			ft_putuns_maj(unsigned long long n);
int				ft_size_chain_uns(char *s, int t_arg, int diff);
int				ft_size_chain_uns_plus(char *s, int t_arg, int diff);
int				ft_putspace_uns_bis(int auth, int flag, int flag_z,
				int check_type);
int				ft_uns_size(char *s, int check_type);
void			ft_putuns(unsigned n);
void			ft_putuns_short(unsigned short n);
void			ft_putuns_short2(unsigned char n);
void			ft_putuns_max(intmax_t n);
void			ft_putuns_size(size_t n);
int				ft_putspace_str(int auth, int flag, int flag_z, int check_type);
int				ft_handle_str(char *s, void *arg, int check_type);
int				ft_putstr1(char const *s);
size_t			ft_strnlen(const char *s);
int				ft_putnstr(char const *s, int n);
int				ft_putstr_f(char *s, va_list *p);
int				ft_strwlen(wchar_t *s);
int				ft_putstr_maj(wchar_t *s);
int				ft_putnstr_maj(wchar_t *s, int n);
int				ft_cptnstr(wchar_t *s, int n);
int				ft_putstr_maj_f(char *s, va_list *p);
int				ft_size_chain_str_plus(char *s, int t_arg, int diff, char *arg);
int				ft_size_chain_str_plus_maj(char *s, int t_arg, int diff,
				wchar_t *arg);
int				ft_size_chain_str(char *s, int t_arg, int diff, char *arg);
int				ft_size_chain_str_maj(char *s, int t_arg, int diff,
				wchar_t *arg);
int				ft_putspace_str_bis(int auth, int flag, int flag_z,
				int check_type);
int				ft_str_size(char *s, void *arg, int check_type);
int				ft_putpercent_f(char *s, va_list *p);
int				ft_putdieses_oct(char *s);
int				ft_oct_size(char *s, int check_type);
int				ft_putoctal_z(char *s, va_list *p);
int				ft_putoctal_hh(char *s, va_list *p);
int				ft_putoctal_h(char *s, va_list *p);
int				ft_putoctal_l(char *s, va_list *p);
int				ft_putoctal_f(char *s, va_list *p);
int				ft_putoctal_j(char *s, va_list *p);
int				ft_putoctal_maj_f(char *s, va_list *p);
int				ft_size_chain_oct(char *s, int t_arg, int diff, int arg);
int				ft_size_chain_oct_plus(char *s, int t_arg, int diff);
void			ft_putoctal_long(unsigned long long n);
void			ft_putoctal_max(intmax_t n);
void			ft_putoctal_size(size_t n);
int				ft_putoctal_short2(unsigned char n);
int				ft_putoctal_short(unsigned short n);
int				ft_nbr_octal_len_maj(unsigned long long nb);
int				ft_nbr_octal_len(size_t nb);
void			ft_putoctal(unsigned n);
int				ft_putplus_nbr_bis_maj(char *s, ssize_t arg);
int				ft_putspace_nbr_bis(int auth, int flag, int flag_z);
int				ft_nbr_size(char *s, int arg);
int				ft_putnbr_ll(char *s, va_list *p);
int				ft_putnbr_maj_f(char *s, va_list *p);
int				ft_putnbr_j(char *s, va_list *p);
int				ft_putnbr_z(char *s, va_list *p);
int				ft_putnbr_hh(char *s, va_list *p);
int				ft_putnbr_h(char *s, va_list *p);
int				ft_putnbr_0(char *s, int arg);
int				ft_putnbr_f(char *s, va_list *p);
int				ft_size_chain_nbr_less(char *s, int t_arg, int diff,
				ssize_t arg);
int				ft_size_chain_nbr_plus_bis(char *s, int t_arg, int diff);
int				ft_size_chain_nbr(char *s, int t_arg, int diff, ssize_t arg);
int				ft_size_chain_nbr_plus(char *s, int t_arg, int diff);
void			ft_putnbr_short2(signed char n);
void			ft_putnbr_short(short int n);
int				ft_putnbr_max(intmax_t n);
void			ft_putnbr_size(size_t n);
void			ft_putnbr_long(int long n);
void			ft_putnbr_long2(long long n);
void			ft_putnbr1(int n);
int				ft_putdieses_hexa(char *s);
int				ft_hexa_size(char *s, int arg, int check_type);
int				ft_strhlen(size_t nb);
int				ft_puthexa_l(char *s, va_list *p);
int				ft_puthexa_h(char *s, va_list *p);
int				ft_puthexa_j(char *s, va_list *p);
int				ft_puthexa_z(char *s, va_list *p);
int				ft_puthexa_f(char *s, va_list *p);
int				ft_puthexa_maj_j(char *s, va_list *p);
int				ft_puthexa_maj_z(char *s, va_list *p);
int				ft_puthexa_maj_l(char *s, va_list *p);
int				ft_puthexa_maj_f(char *s, va_list *p);
int				ft_puthexa_maj_h(char *s, va_list *p);
int				ft_size_chain_hexa_maj(char *s, int t_arg, int diff,
				ssize_t arg);
int				ft_size_chain_hexa_plus_maj(char *s, int t_arg, int diff);
int				ft_size_chain_hexa(char *s, int t_arg, int diff, ssize_t arg);
int				ft_size_chain_hexa_plus(char *s, int t_arg, int diff);
void			ft_puthexa_long(unsigned long long nb);
void			ft_puthexa_short(unsigned short nb);
void			ft_puthexa_short2(unsigned char nb);
void			ft_puthexa_max(size_t nb);
void			ft_puthexa_size(size_t nb);
void			ft_puthexa(unsigned nb);
void			ft_puthexa_size_maj(size_t nb);
void			ft_puthexa_short_maj(unsigned short nb);
void			ft_puthexa_max_maj(size_t nb);
void			ft_puthexa_maj_long(unsigned long long n);
void			ft_puthexa_maj(unsigned int n);
int				ft_putspace_char(int auth, int flag, int flag_z,
				int check_type);
int				ft_char_size(char *s, int check_type);
int				ft_putspace_char_bis(int auth, int flag, int flag_z,
				int check_type);
int				ft_handle_char(char *s, int check_type);
int				ft_putchar_f(char *s, va_list *p);
int				ft_strwclen(wchar_t arg);
void			ft_putchar_maj(wchar_t c);
int				ft_putchar_maj_f(char *s, va_list *p);
int				ft_size_chain_char(char *s, int t_arg, int diff);
int				ft_size_chain_char_plus(char *s, int t_arg, int diff);
int				ft_add_size(char *s, int long arg, int check_type);
int				ft_handle_add(char *s, int long arg, int check_type);
int				ft_nbr_add_len(size_t nb);
void			ft_putadd(unsigned long nb);
int				ft_putadd_f(char *s, va_list *p);
int				ft_size_chain_add_plus(char *s, int t_arg, int diff);
int				ft_size_chain_add(char *s, int t_arg, int diff);
int				ft_putplus_nbr_bis(char *s, ssize_t arg);
int				ft_putuns_0(char *s, int arg);
int				ft_putoctal_0(char *s, int arg);
int				ft_putnbr_0(char *s, int arg);
int				ft_puthexa_0(char *s, int arg);
int				ft_puthexa_0(char *s, int arg);
int				ft_putadd_0(char *s, int arg);
int				ft_puthexa_maj_0(char *s, int arg);
int				ft_puthexa_maj_hh(char *s, va_list *p);
void			ft_puthexa_short_maj2(unsigned char nb);
int				ft_check_letter_o(char *s);
void			ft_putbin(unsigned long long nb);
int				ft_putbin_f(char *s, va_list *p);
int				ft_size_chain_bin_plus(char *s, int t_arg, int diff);
int				ft_size_chain_bin(char *s, int t_arg, int diff);

#endif
