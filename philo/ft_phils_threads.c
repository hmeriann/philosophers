/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2022/01/11 19:11:26 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_simulation(void *phil)
{
	t_phs	*curr_phil;

	curr_phil = (t_phs *)phil;
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
		if (curr_phil->is_dead == 0)
		{
			ft_print_state(curr_phil, SLEEP);
			ft_my_sleep_ms(curr_phil->settings->time_to_sleep);
			ft_print_state(curr_phil, THINK);
		}
	}
	return (NULL);
}

int	ft_threads(t_sets *settings, t_phs *phils)
{
	int			i;
	pthread_t	*phils_thread;

	i = 0;
	phils_thread = malloc(sizeof(pthread_t) * settings->philos_count);
	if (!phils_thread)
		return (MALERR);
	while (i < settings->philos_count)
	{
		if (pthread_create(&phils_thread[i], NULL, \
			ft_simulation, (void *)&phils[i]))
			return (THRERR);
		i++;
	}
	i = 0;
	while (i < settings->philos_count)
	{
		if (pthread_detach(phils_thread[i]))
			return (THRERR);
		i++;
	}
	settings->phs_threads = phils_thread;
	return (0);
}

int	ft_at_the_table(t_sets *settings, t_phs *phils)
{
	int	err_code;
	int	i;

	i = 0;
	settings->time = ft_get_time_ms();
	while (i < settings->philos_count)
	{
		settings->philo[i].last_eat_time = settings->time;
		i++;
	}
	err_code = ft_threads(settings, phils);
	if (err_code)
		return (err_code);
	(err_code = ft_watcher(phils));
	if (err_code != 0)
		return (err_code);
	else if (err_code)
	{
		free(settings->phs_threads);
		if (ft_forks_destroy(settings) != 0)
			return (FORERR);
		return (0);
	}
	return (0);
}
