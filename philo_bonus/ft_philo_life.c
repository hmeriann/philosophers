/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:24:34 by zu                #+#    #+#             */
/*   Updated: 2022/01/15 18:07:11 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_take_forks_and_eat(t_phs *phil)
{
	sem_wait(phil->settings->taking);
	sem_wait(phil->settings->forks);
	ft_print_state_bonus(phil, FORK);
	sem_wait(phil->settings->forks);
	ft_print_state_bonus(phil, FORK);
	sem_post(phil->settings->taking);
	ft_print_state_bonus(phil, EAT);
	phil->time_to_be_hungry = ft_get_time_ms_bonus();
	ft_my_sleep_ms_bonus(phil->settings->time_to_eat);
	sem_post(phil->settings->forks);
	sem_post(phil->settings->forks);
	if (phil->settings->should_eat_times)
	{
		phil->already_ate++;
		if (phil->already_ate == phil->settings->should_eat_times)
			exit(0);
	}
}

void	*ft_philo_life(void	*philo)
{
	t_phs	*curr_phil;

	curr_phil = philo;
	if (((curr_phil->pos_in_arr + 1) % 2) == 0)
		usleep(500);
	ft_watch_bns(curr_phil);
	while (1)
	{
		ft_take_forks_and_eat(curr_phil);
		ft_print_state_bonus(curr_phil, SLEEP);
		ft_my_sleep_ms_bonus(curr_phil->settings->time_to_sleep);
		ft_print_state_bonus(curr_phil, THINK);
	}
	return (NULL);
}
