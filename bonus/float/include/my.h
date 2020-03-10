/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header of my lib
*/

#ifndef MY_H_
#define MY_H_

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b
#define ISNEG(nb) nb < 0 ? 1 : 0

void my_putchar(char c);
int my_put_nbr(int nb);
int set_base(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int calc_number(char const *str, int nb, int index, int neg);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr (char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_base_pos(int nbr, char const *base);
int my_getnbr_base(char const *str, char const *base);
int calc_number_base(char const *str, char const *base, int nb, int neg);
int my_strlen(char const *str);
int char_in_base(char c, char const *base);
char **my_str_to_word_array(char const *str);
char *my_strdup(char *str);
int my_show_word_array(char * const *tab);
int get_color(unsigned char red, unsigned char green, unsigned char blue);
struct info_param *my_params_to_array(int ac, char **av);
void put_info_in_struct(char *str, struct info_param *par);
void params_to_array(int ac, char **av, struct info_param *tab);
int my_show_param_array(struct info_param const *par);
void my_putstrln(char *str);
int swap_endian_color(int color);
int power_n(int base, int n);
int make_even(int nb);
void put_nbr_base(char const *base, int index, int base_n, int nbr);
int power_n_pos(int base, int n);
int make_even_pos(int nb);
char const *put_word_in_array(char **word_array, char const *str, int index);
int isalphanum(char c);
int count_valid_words(char const *str);
int check_is_new_word(char c);
void capitalizer(char *str, int is_new_word);
int is_same(char *str, char const *to_find);
void put_hexa_char(char c);
void my_memset(char *str, int n, char value);

#endif /* !MY_H_ */
