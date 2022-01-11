NAME =	philo_bonus

SRC =	ft_philo_bonus_main.c	ft_philo_utils_bonus.c	ft_save_settings_bonus.c ft_phils_threads_bonus.c\
		ft_time_bonus.c	ft_inits_bonus.c ft_phil_eats_bonus.c ft_watching_bonus.c ft_print_err_bonus.c\
		ft_inits.c \

INCLUDES= philo_bonus.h

OBJ =	$(SRC:.c=.o)
FLAGS =	-g -Wall -Wextra -Werror -fsanitize=address

all:	$(NAME)

.o: .c $(INCLUDES)
		gcc $(FLAGS) -c $< -o $@

$(NAME): $(OBJ) $(INCLUDES)
		gcc $(FLAGS) $(OBJ) -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

norm:	norminette $(SRC) philo_bonus.h

.PHONY: all clean fclean re
