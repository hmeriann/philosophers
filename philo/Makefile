NAME =	philo

SRC =	main.c	ft_philo_utils.c	ft_save_settings.c	ft_phils_threads.c\
		ft_time.c	ft_inits.c	ft_watching.c	ft_print_err.c\
		ft_print_status.c\

INCLUDES= philo.h

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

.PHONY: all clean fclean re
