NAME =	philo

SRC =	ft_philo_main.c	ft_philo_utils.c	ft_init_settings.c	ft_prepare_simulation.c\
		ft_check_args.c	ft_create_philos.c	\

OBJ =	$(SRC:.c=.o)
FLAGS =	-g -Wall -Wextra -Werror

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
