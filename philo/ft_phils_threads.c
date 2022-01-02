/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2022/01/02 23:36:54 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_state(t_phs *curr_phil, int state)
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
		{
			time_spent = ft_get_time_ms() - curr_phil->settings->time;
			printf("%d ms philosopher #%d died\n", \
				time_spent, curr_phil->order);
		}
		pthread_mutex_unlock((curr_phil->settings->print));
	}
	else
		pthread_mutex_unlock((curr_phil->settings->print));
}

static void	*ft_simulation(void *phil)
{
	t_phs	*curr_phil;
	int		eat_times;

	curr_phil = (t_phs *)phil;
	eat_times = curr_phil->settings->should_eat_times;
	while (1)
	{
		if (pthread_mutex_lock(curr_phil->mutex_left_f) == 0 && \
			pthread_mutex_lock(curr_phil->mutex_right_f) == 0)
		{
			curr_phil->last_eat_time = ft_get_time_ms();
			curr_phil->already_ate += 1;
			ft_phil_eats(curr_phil);
			pthread_mutex_unlock(curr_phil->mutex_left_f);
			pthread_mutex_unlock(curr_phil->mutex_right_f);
		}
		ft_my_sleep_ms(curr_phil->settings->time_to_eat);
		ft_print_state(curr_phil, SLEEP);
		ft_my_sleep_ms(curr_phil->settings->time_to_sleep);
		ft_print_state(curr_phil, THINK);
	}
	return (0);
}

int	ft_phils_threads(t_sets *settings, t_phs *phils)
{
	pthread_t	*phils_thread;
	int			i;

	i = 0;
	phils_thread = malloc(sizeof(pthread_t) * settings->philos_count);
	if (!phils_thread)
		return (1);
	settings->time = ft_get_time_ms();
	while (i < settings->philos_count)
	{
		if (pthread_create(&phils_thread[i], NULL, \
			ft_simulation, (void *)&phils[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < settings->philos_count)
	{
		if (pthread_detach(phils_thread[i]))
			return (1);
		i++;
	}
	if (ft_watcher(phils) != 0)
		ft_exit(1, phils);
	if (ft_forks_destroy(settings) != 0)
		ft_exit(1, phils);
	free(phils_thread);
	return (0);
}
