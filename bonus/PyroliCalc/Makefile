##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c				\
		src/create_my_window.c			\
		src/events_calc.c			\
		src/init_struct.c			\
		src/my_calc.c				\
		src/set_sprites.c			\
		src/set_text.c				\
		../../src/eval_expr.c			\
		../../src/expr_utils2.c			\
		../../src/expr_utils.c			\
		../../src/infinadd.c			\
		../../src/infindiv.c			\
		../../src/infinmod.c			\
		../../src/infinmult.c			\
		../../src/infin_opps_utils.c		\
		../../src/infinsub.c			\
		../../src/invalid_syntax_checking.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	pyrolicalc

CFLAGS	=	-W -Wall -I ../../include/ -I include/

CSFML	=	-lcsfml-audio -lcsfml-window -lcsfml-system -lcsfml-graphics

LDFLAGS	=	-L ../../lib/my -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../../lib/my
	$(CC) -o $(NAME) $(CSFML) $(OBJ) $(LDFLAGS)

clean:
	rm -f *~
	rm -f $(OBJ)
	make clean -C ../../lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C ../../lib/my

re:	fclean all

.PHONY:	all clean fclean re
