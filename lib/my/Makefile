##
## EPITECH PROJECT, 2019
## Makefile for
## File description:
##
##

CC =		gcc

RM = 		rm -rf

NAME =		libmy.a

SRC =		my_swap.c \
		my_strupcase.c \
		my_compute_power_rec.c \
		my_compute_square_root.c \
		my_find_prime_sup.c \
		my_getnbr.c \
		my_getnbr_base.c \
		my_is_prime.c \
		my_put_nbr.c \
		my_putchar.c \
		my_putnbr_base.c \
		my_putstr.c \
		my_revstr.c \
		my_show_word_array.c \
		my_showstr.c \
		my_sort_int_array.c \
		my_str_isalpha.c \
		my_str_islower.c \
		my_str_isnum.c \
		my_str_isprintable.c \
		my_str_isupper.c \
		my_str_to_word_array.c \
		my_strcapitalize.c \
		my_strcat.c \
		my_strcmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strlen.c \
		my_strlowcase.c \
		my_strncat.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strstr.c \
		my_memset.c

OBJ =		$(SRC:.c=.o)

CFLAGS =	-W -Wall -Wextra -Werror -I headers

all:		$(NAME)

$(NAME):	$(OBJ)
		cp *.h ../../include/
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		cp $(NAME) ../

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
