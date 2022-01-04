/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watching.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 21:26:58 by zu                #+#    #+#             */
/*   Updated: 2022/01/05 00:27:22 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_eat_checker(t_phs *curr_phil, int phils_count)
{
	int	i;

	i = 0;
	while (i < (phils_count - 1))
	{
		if (curr_phil[i].already_ate != curr_phil[i + 1].already_ate)
			return (0);
		i++;
	}
	return (1);
}

int	ft_monitor(t_phs *curr_phil, int phils_count, int i)
{
	int	time_delta;

	time_delta = ft_get_time_ms() - curr_phil[i].last_eat_time;
	if (time_delta > curr_phil[i].settings->time_to_die)
	{
		ft_print_state(curr_phil, DIE);
		curr_phil->settings->stop_flag = 1;
		curr_phil->is_dead = 1;
		return (1);
	}
	if (ft_eat_checker(curr_phil, phils_count) && \
		curr_phil->settings->should_eat_times != -1)
	{
		if (curr_phil[phils_count - 1].already_ate >= \
			curr_phil->settings->should_eat_times)
		{
			curr_phil->settings->stop_flag = 1;
			return (1);
		}
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
	while (curr_phil->settings->stop_flag == 0)
	{
		i = 0;
		while (i < phils_count)
		{
			if (ft_monitor(curr_phil, phils_count, i))
				return (NULL);
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
