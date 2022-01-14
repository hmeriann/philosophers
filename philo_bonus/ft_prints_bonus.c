/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:35:42 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/14 16:47:14 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_print_err_bonus(int err_code)
{
	if (err_code == ARGERR)
		write(2, "Check arguments quantity and try again\n", 39);
	else if (err_code == UNSERR)
		write(2, "Arguments should be only unsigned int\n", 38);
	else if (err_code == ZERERR)
		write(2, "Arguments should be more than zero\n", 35);
	else if (err_code == MALERR)
		write(2, "Malloc error\n", 13);
	else if (err_code == PHIERR)
		write(2, "Phils init error\n", 17);
	else if (err_code == FORERR)
		write(2, "Forks init error\n", 17);
	else if (err_code == THRERR)
		write(2, "Thread error\n", 13);
	else if (err_code == MUTERR)
		write(2, "Mutex error\n", 12);
	else if (err_code == SIGERR)
		write(2, "Signal error\n", 13);
	exit(1);
}

void	ft_print_state_bonus(t_phs *curr_phil, int state)
{
	int		time_spent;

	sem_wait(curr_phil->settings->print);
	time_spent = ft_get_time_ms_bonus() - curr_phil->settings->time;
	if (state == FORK)
		printf("%d ms philosopher #%d has taken a fork\n", \
			time_spent, curr_phil->pos_in_arr + 1);
	if (state == EAT)
		printf("\x1b[34m%d ms philosopher #%d is eating\x1b[0m\n", \
			time_spent, curr_phil->pos_in_arr + 1);
	if (state == SLEEP)
		printf("%d ms philosopher #%d is sleeping\n", \
			time_spent, curr_phil->pos_in_arr + 1);
	if (state == THINK)
		printf("%d ms philosopher #%d is thinking\n", \
			time_spent, curr_phil->pos_in_arr + 1);
	if (state == DIE)
	{
		printf("\x1b[31m%d ms philosopher #%d died\x1b[0m\n", \
			time_spent, curr_phil->pos_in_arr + 1);
		exit(1);
	}
	sem_post(curr_phil->settings->print);
}
