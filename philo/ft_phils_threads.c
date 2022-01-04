/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2022/01/04 16:27:47 by hmeriann         ###   ########.fr       */
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
			printf("%d ms philosopher #%d died\n", \
				time_spent, curr_phil->order);
		pthread_mutex_unlock((curr_phil->settings->print));
	}
	else
		pthread_mutex_unlock((curr_phil->settings->print));
}

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
		ft_print_state(curr_phil, SLEEP);
		ft_my_sleep_ms(curr_phil->settings->time_to_sleep);
		ft_print_state(curr_phil, THINK);
		// if (curr_phil->already_ate == curr_phil->settings->should_eat_times)
		// {
		// 	printf(">>> philosopher #%d already ate %d times\n", \
		// 		curr_phil->order, curr_phil->already_ate);
		// 	break ;
		// }
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
		usleep(1);
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

	settings->time = ft_get_time_ms();
	err_code = ft_threads(settings, phils);
	if (err_code)
		return (err_code);
	(err_code = ft_watcher(phils));
	if (err_code)
		return (err_code);
	free(settings->phs_threads);
	if (ft_forks_destroy(settings) != 0)
		return (FORERR);
	return (0);
}
