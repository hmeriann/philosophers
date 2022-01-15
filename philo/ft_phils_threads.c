/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2022/01/15 18:39:17 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_simulation(void *phil)
{
	t_phs	*curr_phil;

	curr_phil = (t_phs *)phil;
	while (1)
	{
		if (curr_phil->order % 2 == 0)
			usleep(300);
		pthread_mutex_lock(curr_phil->mutex_left_f);
		ft_print_state(curr_phil, FORK);
		pthread_mutex_lock(curr_phil->mutex_right_f);
		ft_print_state(curr_phil, FORK);
		curr_phil->last_eat_time = ft_get_time_ms();
		ft_print_state(curr_phil, EAT);
		ft_my_sleep_ms(curr_phil->settings->time_to_eat);
		curr_phil->already_ate++;
		pthread_mutex_unlock(curr_phil->mutex_left_f);
		pthread_mutex_unlock(curr_phil->mutex_right_f);
		ft_print_state(curr_phil, SLEEP);
		ft_my_sleep_ms(curr_phil->settings->time_to_sleep);
		ft_print_state(curr_phil, THINK);
	}
	return (NULL);
}

int	ft_threads(t_sets *settings, t_phs *phils)
{
	int			i;
	pthread_t	*phils_thread;

	i = 0;
	phils_thread = malloc(sizeof(pthread_t) * settings->philos_count);
	settings->time = ft_get_time_ms();
	if (!phils_thread)
		return (MALERR);
	while (i < settings->philos_count)
	{
		phils[i].last_eat_time = settings->time;
		if (pthread_create(&phils_thread[i], NULL, \
			ft_simulation, (void *)&phils[i]))
			return (THRERR);
		usleep(100);
		i++;
	}
	while (i < settings->philos_count)
	{
		if (pthread_detach(phils_thread[i]))
			return (THRERR);
		i--;
	}
	settings->phs_threads = phils_thread;
	return (0);
}

int	ft_at_the_table(t_sets *settings, t_phs *phils)
{
	int	err_code;
	int	i;

	i = 0;
	err_code = ft_threads(settings, phils);
	if (err_code)
		return (err_code);
	(err_code = ft_watcher(phils));
	if (err_code != 0)
    {
        free(settings->phs_threads);
        if (ft_forks_destroy(settings) != 0)
            return (FORERR);
        return (0);
    }
    return (0);
}
