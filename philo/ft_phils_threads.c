/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2021/12/29 00:09:50 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_simulation(void *anything)
{
	t_phs	*thing;

	thing = (t_phs *)anything;
	printf("simulation phil #%d\n", thing->order);
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
	while (i < settings->philos_count)
	{
		if (pthread_create(&phils_thread[i], NULL, ft_simulation, (void *)&phils[i]))
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
	return (0);
}
