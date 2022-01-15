NAME =	philo_bonus

SRC =	ft_inits_bonus.c ft_philo_bonus_main.c	ft_philo_life.c ft_philo_utils_bonus.c \
		ft_print_err_bonus.c ft_print_status_bonus.c ft_save_settings_bonus.c ft_sig.c \
		ft_time_bonus.c ft_watcher_bonus.c\

INCLUDES= philo_bonus.h

OBJ =	$(SRC:.c=.o)
FLAGS =	-g -Wall -Wextra -Werror

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
