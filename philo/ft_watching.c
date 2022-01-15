/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watching.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:26:58 by zu                #+#    #+#             */
/*   Updated: 2022/01/15 22:47:52 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitor(t_phs curr_phil, int phils_count)
{
	int	time_delta;

	time_delta = ft_get_time_ms() - curr_phil.last_eat_time;
	if (time_delta > curr_phil.settings->time_to_die)
	{
		ft_print_state(&curr_phil, DIE);
		pthread_mutex_unlock(curr_phil.mutex_left_f);
		pthread_mutex_unlock(curr_phil.mutex_right_f);
		return (1);
	}
	if (curr_phil.settings->should_eat_times != -1)
	{
		if (curr_phil.already_ate == curr_phil.settings->should_eat_times)
			return (1);
	}
	return (0);
}

void	*ft_watching(void *phil)
{
	t_phs	*curr_phil;
	int		phils_count;
	int		i;

	curr_phil = (t_phs *)phil;
	phils_count = curr_phil->settings->philos_count;
	while (1)
	{
		i = 0;
		while (i < phils_count)
		{
			if (ft_monitor(curr_phil[i], phils_count))
				return (NULL);
			i++;
		}
	}
	return (NULL);
}

int	ft_watcher(t_phs *phils)
{
	pthread_t	watcher;

	if (pthread_create(&watcher, NULL, ft_watching, (void *)phils) != 0)
		return (THRERR);
	if (pthread_join(watcher, NULL))
		return (THRERR);
	return (0);
}
