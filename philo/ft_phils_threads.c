/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2021/12/30 20:01:04 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_simulation(void *anything)
{
	t_phs	*thing;
	int		time_spent;

	thing = (t_phs *)anything;
	while (1)
	{
		if (pthread_mutex_lock(thing->mutex_left_f) == 0 && \
			pthread_mutex_lock(thing->mutex_right_f) == 0)
		{
			thing->last_eat_time = ft_get_time_ms();
			thing->already_ate += 1;
			//сообщение, что он взял вилки и ест - 3 сообщения
			// ft_print_status((int)(ft_get_time_ms() - thing->settings->time), thing->order, );
			time_spent = ft_get_time_ms() - thing->settings->time;
			printf("%d ms philosopher #%d is took a fork\n", time_spent, thing->order);
			time_spent = ft_get_time_ms() - thing->settings->time;
			printf("%d ms philosopher #%d is took a fork\n", time_spent, thing->order);
			time_spent = ft_get_time_ms() - thing->settings->time;
			printf("%d ms philosopher #%d is eating\n", time_spent, thing->order);
			ft_my_sleep_ms(thing->settings->time_to_eat);
			pthread_mutex_unlock(thing->mutex_left_f);
			pthread_mutex_unlock(thing->mutex_right_f);
			printf("%d ms philosopher #%d is sleeping\n", time_spent, thing->order);
			// printf("%d\n", (int)(thing->last_eat_time - thing->settings->time));
			//спит
			//думает
			// printf("simulation phil #%d last time eat %ld already ate %d\n", thing->order, (thing->last_eat_time - thing->settings->time), thing->already_ate);
			if (thing->already_ate == 3)
				break ;
		}
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
		if (pthread_join(phils_thread[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
