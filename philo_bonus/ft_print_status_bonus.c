/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:19:01 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/11 19:59:14 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print_state_bonus(t_phs *curr_phil, int state)
{
	int		time_spent;

	if (pthread_mutex_lock((curr_phil->settings->print)) == 0)
	{
		time_spent = ft_get_time_ms() - curr_phil->settings->time;
		if (state == FORK)
			printf("%d ms philosopher #%d has taken a fork\n", \
				time_spent, curr_phil->order);
		if (state == EAT)
			printf("%d ms philosopher #%d is eating\n", \
				time_spent, curr_phil->order);
		if (state == SLEEP)
			printf("%d ms philosopher #%d is sleeping\n", \
				time_spent, curr_phil->order);
		if (state == THINK)
			printf("%d ms philosopher #%d is thinking\n", \
				time_spent, curr_phil->order);
		if (state == DIE)
			printf("%d ms philosopher #%d died\n", \
				time_spent, curr_phil->order);
		pthread_mutex_unlock((curr_phil->settings->print));
	}
	else
		pthread_mutex_unlock((curr_phil->settings->print));
}
