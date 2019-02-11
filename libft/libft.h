/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:26:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/12/06 16:02:51 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <math.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_ahtoi(char const *str);
int					ft_atoi(char const *str);
long				ft_atol(char const *str);
float				ft_atof(char const *str);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
size_t				ft_lstlen(t_list *lst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lst_last_link(t_list **lst, t_list *new);

char				*ft_dtoa(double n, unsigned int precision);
char				*ft_itoa(int n);
char				*ft_itoa_base(intmax_t number, int base);
char				*ft_ltoa(long n);
char				*ft_ftoa(float n);
char				*ft_ldbltoa(long double n);

int					ft_int_fact(int n);

int					ft_abs(int i);
float				ft_fabs(float f);

void				ft_bzero(void *s, size_t n);

void				*ft_memset(void *b, int c, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memccpy(void *dst, void const *src, int c, size_t n);
void				*ft_memchr(void const *s, int c, size_t n);
void				*ft_memmove(void *dst, void const *src, size_t len);

void				ft_putnbr(int n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
int					ft_putwchar(wchar_t c);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putwstr(wchar_t const *str);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);

int					ft_wcharlen(wchar_t c);
int					ft_wstrlen(wchar_t *str);
int					ft_wstrlen_false(wchar_t *str);

void				ft_error(char *error_str);
void				ft_error_if(int boo, char *error_str);

char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
size_t				ft_strlen(char const *s);
char				*ft_strtrim(char const *s);
char				*ft_strtrim_free(char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *str, char c);

char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);

char				*ft_strdup(char const *s1);
char				*ft_strdup_free(char *s1);

char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *s1, char *s2);
char				*ft_strjoin_frs1(char *s1, char *s2);
char				*ft_strjoin_frs2(char *s1, char *s2);

char				*ft_strstr(char const *s1, char const *s2);
char				*ft_strnstr(char const *s1, char const *s2, size_t n);

char				*ft_strcat(char *restrict s1, char const *restrict s2);
size_t				ft_strlcat(char *dst, char const *src
							, size_t size);
char				*ft_strncat(char *restrict s1, char const *restrict s2
							, size_t n);

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strcpy(char *dst, char const *src);
char				*ft_strncpy(char *dst, char const *src, size_t len);

int					ft_strcmp(char const *s1, char const *s2);
int					ft_strncmp(char const *s1, char const *s2, size_t n);

int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_intlen(int n);
int					ft_longlen(long n);

int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isalphalowercase(int c);
int					ft_isalphauppercase(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

int					ft_pow(int n, int e);
double				ft_dpow(double n, double e);

double				ft_cos(double angle);
double				ft_sin(double angle);
double				ft_tan(double angle);

#endif
