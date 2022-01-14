/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_watcher_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:41:30 by zu                #+#    #+#             */
/*   Updated: 2022/01/14 21:11:37 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_watch_bns(t_phs *phil)
{
	pthread_t	watcher;

	watcher = malloc(sizeof(pthread_t));
	if (pthread_create(&watcher, NULL, check_if_dead, (void *)phil))
		return (THRERR);
	if (pthread_detach(watcher))
		return (THRERR);
	return (0);
}

void	*check_if_dead(void *phils)
{
	int		i;
	t_phs	*curr_phil;

	i = 0;
	curr_phil = (t_phs *)phils;
	while (1)
	{
		if (i >= curr_phil->settings->philos_count)
			i = 0;
		if ((ft_get_time_ms_bonus() - curr_phil->time_to_be_hungry) \
				> curr_phil->settings->time_to_die)
			ft_print_state_bonus(curr_phil, DIE);
		i++;
		usleep(100);
	}
	return (NULL);
}
