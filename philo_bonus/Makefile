NAME =	philo

SRC =	ft_philo_main_bonus.c	ft_philo_utils_bonus.c	ft_save_settings_bonus.c	ft_phils_threads_bonus.c\
		ft_time_bonus.c	ft_inits_bonus.c	ft_phil_eats_bonus.c ft_watching_bonus.c	ft_print_err_bonus.c\

OBJ =	$(SRC:.c=.o)
FLAGS =	-g -Wall -Wextra -Werror -fsanitize=address

all:	$(NAME)

$(NAME): $(OBJ)
		gcc $(FLAGS) $(OBJ) -o $@

%.o: %.c
		gcc $(FLAGS) -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

norm:	norminette $(SRC) philo_bonus.h

.PHONY: all clean fclean re
