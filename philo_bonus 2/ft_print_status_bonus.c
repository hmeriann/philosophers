/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:19:01 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/14 21:18:20 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
