/*
** EPITECH PROJECT, 2019
** bistromatic.h
** File description:
** header for bistro-matic
*/

#ifndef BISTROMATIC_H_
#define BISTROMATIC_H_

#define OP_OPEN_PARENT_IDX 0
#define OP_CLOSE_PARENT_IDX 1
#define OP_PLUS_IDX 2
#define OP_SUB_IDX 3
#define OP_NEG_IDX 3
#define OP_MULT_IDX 4
#define OP_DIV_IDX 5
#define OP_MOD_IDX 6

#define EXIT_SYNTAX_ERROR 84
#define EXIT_SIZE_NEG 84
#define EXIT_MALLOC 84
#define EXIT_USAGE 84
#define EXIT_BASE 84
#define EXIT_READ 84
#define EXIT_OPS 84

char const *SYNTAX_ERROR_MSG;
char const *ERROR_MSG;

typedef struct expr
{
    unsigned int base_size;
    char const *base;
    char const *ops;
    char const *expr;
} expr_t;

typedef struct number
{
    char *nb;
    unsigned int len;
    signed char sign;
} nb_t;

int check_eval_expr(int ac, char **av);

nb_t *eval_expr(char const *base, char const *ops, char const *expr);

void infinadd(expr_t *expr, nb_t *infin_nums[2]);
void infinsub(expr_t *expr, nb_t *infin_nums[2]);
void infinmult(expr_t *expr, nb_t *infin_nums[2]);
void infindiv(expr_t *expr, nb_t *infin_nums[2]);
void infinmod(expr_t *expr, nb_t *infin_nums[2]);

int my_strcmp_custom(char const *s1, char const *s2, char const *base);
int find_lowest(nb_t *infin_nums[2], char const *base);
int get_index_base(char digit, char const *base);

int invalid_syntax_checking(expr_t *expr);

void do_high_op(expr_t *expr, nb_t *infin_nums[2], char op);
void do_low_op(expr_t *expr, nb_t *infin_nums[2]);
int is_op_high(char const *ops, char c);
int is_op_low(char const *ops, char c);

void invalid_op_exit(expr_t *expr, nb_t *infin_nums[2]);
unsigned int get_nb_size(expr_t *expr);
int c_in_str(char c, char const *str);
void check_malloc(void *item);

#endif /* !BISTROMATIC_H_ */
