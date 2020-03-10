##
## EPITECH PROJECT, 2019
## Makefile for do_op
## File description:
## do_op
##

CC =		gcc

NAME =		calc

TEST =		unit_tests

SRC =		src/main.c				\
		src/check_eval_expr.c			\
		src/eval_expr.c				\
		src/get_number.c			\
		src/expr_utils.c			\
		src/expr_utils2.c			\
		src/expr_utils3.c			\
		src/infin_opps_utils.c			\
		src/infinadd.c				\
		src/infinsub.c				\
		src/infinmult.c				\
		src/infindiv.c				\
		src/infinmod.c				\
		src/infinpow.c				\
		src/invalid_syntax_checking.c		\

SRCT =		tests/test_eval_expr.c			\
		tests/test_eval_expr2.c			\
		tests/test_eval_expr_base.c		\
		tests/test_eval_expr_error.c		\
		tests/test_eval_expr_error2.c		\
		tests/test_eval_expr_add.c		\
		tests/test_eval_expr_sub.c		\
		tests/test_eval_expr_mult.c		\
		tests/test_eval_expr_div.c		\
		tests/test_eval_expr_mod.c		\
		tests/test_infinadd.c			\
		tests/test_infinsub.c			\
		tests/test_infinmult.c			\
		tests/test_infindiv.c			\
		tests/test_infinmod.c			\
		tests/test_infinpow.c			\
		tests/test_invalid_syntax_checking.c	\
		src/eval_expr.c				\
		src/expr_utils.c			\
		src/expr_utils2.c			\
		src/expr_utils3.c			\
		src/infin_opps_utils.c			\
		src/infinadd.c				\
		src/infinsub.c				\
		src/infinmult.c				\
		src/infindiv.c				\
		src/infinmod.c				\
		src/invalid_syntax_checking.c		\


OBJ =		$(SRC:.c=.o)

CFLAGS =	-W -Wall -Wextra -g3

CPPFLAGS =	-I include/

LDFLAGS =	-L lib -lmy

TFLAGS =	--coverage -lcriterion

all:		$(NAME)

tests_run:
		make -C lib/my/
		$(CC) $(CFLAGS) $(SRCT) -o $(TEST) $(CPPFLAGS) $(LDFLAGS) $(TFLAGS)
		./$(TEST)

$(NAME):	$(OBJ)
		make -C lib/my/
		$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJ) *.gc*
		make clean -C lib/my/

fclean:		clean
		$(RM) $(NAME) $(TEST)
		make fclean -C lib/my/

re:		fclean all

.PHONY: all clean fclean re tests_run
