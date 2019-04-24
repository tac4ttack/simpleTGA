# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 23:18:40 by fmessina          #+#    #+#              #
#    Updated: 2019/04/24 13:04:43 by fmessina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =		simpleTGA.a

CC =		clang
CFLAGS +=	-Wall -Wextra -Werror $(DEBUGFLAGS) $(ASANFLAGS)

SRC =		tga_blackwhite_8bpp.c \
			tga_colormapped_8bpp.c \
			tga_colormapped_15bpp.c \
			tga_colormapped_16bpp.c \
			tga_colormapped_24bpp.c \
			tga_colormapped_32bpp.c \
			tga_error.c \
			tga_load_file.c \
			tga_process_file.c \
			tga_process_pixels.c \
			tga_process_rawbw.c \
			tga_process_rawcm.c \
			tga_process_rawtc.c \
			tga_process_rle_packet.c \
			tga_process_rlebw.c \
			tga_process_rlecm.c \
			tga_process_rletc.c \
			tga_truecolor_15bpp.c \
			tga_truecolor_16bpp.c \
			tga_truecolor_24bpp.c \
			tga_truecolor_32bpp.c

OFILES =	$(SRC:.c=.o)

all: Makefile $(NAME)

$(NAME): simpleTGA.h $(SRC) $(OFILES)
	@echo "Object files successfully created"
	@echo "Building library $(NAME)..."
	@ar rc $(NAME) $(OFILES)
	@echo "Library successfully created"
	@echo "Indexing..."
	@ranlib $(NAME)
	@echo "Library indexed\n"

debug:
	$(eval DEBUGFLAGS = -DDEBUG_TGA -g)

debug_asan: debug
	$(eval ASANFLAGS = -fsanitize=address -fno-omit-frame-pointer)

clean:
	@echo "Cleaning object files..."
	@/bin/rm -f $(OFILES)
	@echo "Object files deleted\n"

fclean: clean
	@echo "Cleaning build and object path..."
	@/bin/rm -f $(NAME)
	@echo "'$(NAME)' file deleted\n"

re: fclean all

.PHONY: all clean fclean re simpleTGA debug debug_asan
