/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:00:11 by zu                #+#    #+#             */
/*   Updated: 2022/01/15 18:24:41 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	giving_forks(t_sets *settings, t_phs *phils)
{
	int	i;

	i = 0;
	while (i < settings->philos_count)
	{
		phils[i].mutex_left_f = \
				&settings->forks[phils[i].order_l_fork];
		phils[i].mutex_right_f = \
				&settings->forks[phils[i].order_r_fork];
		i++;
	}
}

int	ft_init_forks(t_sets *settings, t_phs *phils)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * settings->philos_count);
	if (!forks)
		return (MALERR);
	i = 0;
	if (pthread_mutex_init(settings->print, NULL))
		return (MUTERR);
	while (i < settings->philos_count)
	{
		if (pthread_mutex_init(&(forks[i]), NULL))
		{
			free(forks);
			free(settings->print);
			return (FORERR);
		}
		i++;
	}
	settings->forks = forks;
	giving_forks(settings, phils);
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
		phils[i].order_r_fork = (phils[i].pos_in_arr + 1) % \
			settings->philos_count;
		phils[i].already_ate = 0;
		phils[i].settings = settings;
		i++;
	}
	return (0);
}
