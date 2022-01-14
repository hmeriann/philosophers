/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_life.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:24:34 by zu                #+#    #+#             */
/*   Updated: 2022/01/13 18:54:27 by zu               ###   ########.fr       */
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
		if (phil->already_ate >= phil->settings->should_eat_times)
			phil->settings->stop_flag = 1;
	}
}

void	*ft_philo_life(void	*philo)
{
	t_phs	*curr_phil;

	curr_phil = philo;
	// curr_phil->time_to_be_hungry = ft_get_time_ms_bonus();
	// curr_phil->already_ate = 0;
	if ((curr_phil->order % 2) == 0)
		usleep(500);
	ft_watch_bns(curr_phil);
	while (1)
	{
		ft_take_forks_and_eat(curr_phil);
		ft_print_state_bonus(curr_phil, SLEEP);
		ft_my_sleep_ms_bonus(curr_phil->settings->time_to_sleep);
		ft_print_state_bonus(curr_phil, THINK);
		usleep(100);
	}
	return (NULL);
}
