/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 19:19:01 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/12 15:00:16 by zu               ###   ########.fr       */
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
	{
		printf("%d ms philosopher #%d died\n", \
			time_spent, curr_phil->order);
		exit(1);
	}
	sem_post(curr_phil->settings->print);
}
