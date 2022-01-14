/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_sem_time.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:33:57 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/14 17:32:55 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_get_time_ms_bonus(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_my_sleep_ms_bonus(int time)
{
	long	goal_time;
	long	curr_time;

	curr_time = ft_get_time_ms_bonus();
	goal_time = ft_get_time_ms_bonus() + (long)time;
	while (curr_time < goal_time)
	{
		usleep(50);
		curr_time = ft_get_time_ms_bonus();
	}
}

int	ft_wait_and_kill(t_sets *settings, t_phs *philo)
{
	int	i;
	int	j;

	i = 0;
	while (i < settings->philos_count)
	{
		if (waitpid(0, NULL, 0) < 0)
			return (PIDERR);
		j = 0;
		while (j < settings->philos_count)
		{
			kill(philo[j].pid, SIGKILL);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_init_sem(t_sets *settings)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("death");
	sem_unlink("taking");
	settings->forks = sem_open("fork", O_CREAT, 0777, settings->philos_count);
	settings->print = sem_open("print", O_CREAT, 0777, 1);
	settings->check_dead = sem_open("death", O_CREAT, 0777, 1);
	settings->taking = sem_open("taking", O_CREAT, 0777, 1);
}
