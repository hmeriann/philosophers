NAME =	philo

SRC =	ft_philo_main.c	ft_philo_utils.c	ft_save_settings.c	ft_phils_threads.c\
		ft_time.c	ft_inits.c	ft_phil_eats.c ft_watching.c	ft_print_err.c\

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

norm:	norminette $(SRC) philo.h

.PHONY: all clean fclean re
