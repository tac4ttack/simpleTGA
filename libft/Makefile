# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 23:18:40 by fmessina          #+#    #+#              #
#    Updated: 2017/11/23 16:07:51 by fmessina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		libft.a

CC =		clang
CFLAGS +=	-Wall -Wextra -Werror $(ASANFLAGS)

SRC =		ft_abs.c \
			ft_ahtoi.c \
			ft_atof.c \
			ft_atoi.c \
			ft_atol.c \
			ft_bzero.c \
			ft_cos.c \
			ft_dtoa.c \
			ft_error.c \
			ft_error_if.c \
			ft_fabs.c \
			ft_facti.c \
			ft_ftoa.c \
			ft_intlen.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isalphalowercase.c \
			ft_isalphauppercase.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_ldbltoa.c \
			ft_longlen.c \
			ft_lst_last_link.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_ltoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_pow.c \
			ft_putchar_fd.c \
			ft_putchar.c \
			ft_putendl_fd.c \
			ft_putendl.c \
			ft_putnbr_fd.c \
			ft_putnbr.c \
			ft_putstr_fd.c \
			ft_putstr.c \
			ft_putwchar.c \
			ft_putwstr.c \
			ft_sin.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup_free.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin_free.c \
			ft_strjoin_frs1.c \
			ft_strjoin_frs2.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_strtrim_free.c \
			ft_tan.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_wcharlen.c \
			ft_wstrlen.c \
			ft_wstrlen_false.c \
			get_next_line.c

OFILES =	$(SRC:.c=.o)

all: Makefile $(NAME)

$(NAME): libft.h get_next_line.h $(SRC) $(OFILES)
	@echo "Object files successfully created"
	@echo "Building library $(NAME)..."
	@ar rc $(NAME) $(OFILES)
	@echo "Library successfully created"
	@echo "Indexing..."
	@ranlib $(NAME)
	@echo "Library indexed\n"

debug:
	$(eval ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer -g)

clean:
	@echo "Cleaning object files..."
	@/bin/rm -f $(OFILES)
	@echo "Object files deleted\n"

fclean: clean
	@echo "Cleaning build and object path..."
	@/bin/rm -f $(NAME)
	@echo "'$(NAME)' file deleted\n"

re: fclean all

.PHONY: all clean fclean re
