##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile of infinadd
##

NAME	=	navy

SRC		=	src/read_file.c		\
			src/measure_size.c	\
			src/get_buff.c 		\
			src/str_to_pos.c 	\
			src/init_ship_pos.c \
			src/init_maps.c 	\
			src/fill_map.c 		\
			src/ship_position.c \
			src/print_maps.c 	\
			src/main.c			\
			src/senders.c		\
			src/start_game.c	\
			src/navy.c 			\
			src/get_stdin.c 	\
			src/attacked.c 		\
			src/connection.c	\
			src/init_input.c 	\
			src/print_layout.c 	\
			src/get_signal.c	\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I./include/ -pedantic -g3 -Wpedantic -Wno-long-long -Wall -W -Wextra

LDLIBS	=	-L./lib/ -lmy

all:		$(NAME)

$(NAME):	make_lib $(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDLIBS) -lm

make_lib:
		$(MAKE) -C lib/my

clean:
		rm -f $(OBJ)
		$(MAKE) clean -C lib/my/

fclean: 	clean
		rm -f $(NAME)
		$(MAKE) fclean -C lib/my

re:		fclean all
		$(MAKE) re -C lib/my
