/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phils_threads.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/01/15 18:39:17 by hmeriann         ###   ########.fr       */
=======
/*   Updated: 2022/01/15 15:40:50 by hmeriann         ###   ########.fr       */
>>>>>>> 38c729d7b04e862de2bb7fa814efba2a459616af
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ft_dead_check(void	*phil)
{
	t_phs	*curr_phil;

	curr_phil = (t_phs *)phil;
	while (1)
	{
<<<<<<< HEAD
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
=======
		pthread_mutex_lock(curr_phil->eating);
		if (!curr_phil->now_is_eating && ft_get_time_ms() > \
			curr_phil->time_limit)
		{
			ft_print_state(curr_phil, DIE);
			pthread_mutex_unlock(curr_phil->eating);
			pthread_mutex_unlock(curr_phil->settings->check_dead);
			return (NULL);
		}
		pthread_mutex_unlock(curr_phil->eating);
		usleep(50);
	}
	return (NULL);
}

static void	*ft_simulation(void *phil)
{
	t_phs		*curr_phil;
	pthread_t	help;

	if (pthread_create(&help, NULL, &ft_dead_check, curr_phil))
		return (NULL);
	if (pthread_detach(help))
		return (NULL);
	curr_phil = (t_phs *)phil;
	while (1)
	{
		if (pthread_mutex_lock(curr_phil->mutex_left_f) == 0 && \
			pthread_mutex_lock(curr_phil->mutex_right_f) == 0)
		{
			curr_phil->last_eat_time = ft_get_time_ms();
			curr_phil->already_ate += 1;
			curr_phil->now_is_eating = 1;
			ft_phil_eats(curr_phil);
			curr_phil->now_is_eating = 0;
			pthread_mutex_unlock(curr_phil->mutex_left_f);
			pthread_mutex_unlock(curr_phil->mutex_right_f);
		}
		if (curr_phil->is_dead == 0)
		{
			ft_print_state(curr_phil, SLEEP);
			ft_my_sleep_ms(curr_phil->settings->time_to_sleep);
			ft_print_state(curr_phil, THINK);
		}
>>>>>>> 38c729d7b04e862de2bb7fa814efba2a459616af
	}
	return (NULL);
}

static void	*ft_eat_check(void *settings)
{
	t_sets	*tmp_sets;
	int		i;
	int		meal_count;

	tmp_sets = (t_sets *)settings;
	meal_count = 0;
	while (meal_count < tmp_sets->should_eat_times)
	{
		i = 0;
		while (i < (tmp_sets->philos_count))
			pthread_mutex_lock(tmp_sets->philo[i++].should_e);
		meal_count++;
	}
	pthread_mutex_unlock(tmp_sets->check_dead);
	return (NULL);
}

int	ft_threads(t_sets *settings, t_phs *phils)
{
	int			i;
	pthread_t	*phils_thread;
	pthread_t	eat_check_thread;

	i = 0;
	phils_thread = malloc(sizeof(pthread_t) * settings->philos_count);
	settings->time = ft_get_time_ms();
	if (!phils_thread)
		return (MALERR);
	if (i < settings->should_eat_times)
	{
		if (pthread_create(&eat_check_thread, NULL, &ft_eat_check, settings))
			return (THRERR);
		if (pthread_detach(eat_check_thread))
			return (THRERR);
	}
	i = 0;
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
