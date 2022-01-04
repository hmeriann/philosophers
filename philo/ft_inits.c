/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:00:11 by zu                #+#    #+#             */
/*   Updated: 2022/01/04 15:57:49 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_forks(t_sets *settings, t_phs *phils)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * settings->philos_count);
	settings->print = malloc(sizeof(pthread_mutex_t) * 1);
	if (!forks || !(settings->print))
		return (MALERR);
	i = 0;
	while (i < settings->philos_count)
	{
		if (pthread_mutex_init(&(forks[i]), NULL) || \
			pthread_mutex_init(settings->print, NULL))
		{
			free(forks);
			free(settings->print);
			return (ft_print_err(FORERR));
		}
		i++;
	}
	settings->forks = forks;
	i = 0;
	while (i < settings->philos_count)
	{
		settings->philo[i].mutex_left_f = \
				&settings->forks[phils[i].order_l_fork];
		settings->philo[i].mutex_right_f = \
				&settings->forks[phils[i].order_r_fork];
		i++;
	}
	return (0);
}

int	ft_init_phils(t_sets *settings, t_phs *phils)
{
	int		i;

	i = 0;
	while (i < settings->philos_count)
	{
		phils[i].pos_in_arr = i;
		phils[i].order = i + 1;
		phils[i].order_l_fork = phils[i].pos_in_arr;
		phils[i].order_r_fork = (phils[i].pos_in_arr + 1) % settings->philos_count;
		phils[i].already_ate = 0;
		// phils[i].last_eat_time = settings->time;
		phils[i].settings = settings;
		i++;
	}
	settings->philo = phils;
	return (0);
}
