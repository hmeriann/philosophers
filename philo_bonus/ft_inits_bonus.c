/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:33:57 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/13 18:54:03 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// static void	init_one_phi(t_sets *settings, t_phs **philo, int i)
// {
// 	philo[i]->pos_in_arr = i;
// 	philo[i]->order = i + 1;
// 	philo[i]->fork = settings->forks;
// 	philo[i]->settings = settings;
// }

// int	ft_make_all_phils(t_sets *settings, t_phs **philo)
// {
// 	int	i;
// 	int	pid;

// 	i = 0;
// 	while (i < settings->philos_count)
// 	{
// 		pid = fork();
// 		if (pid < 0)
// 			return (SIGERR);
// 		settings->time = ft_get_time_ms_bonus();
// 		philo[i] = malloc(sizeof(t_phs) * settings->philos_count);
// 		philo[i]->pid = pid;
// 		if (!pid)
// 		{
// 			init_one_phi(settings, philo, i);
// 			ft_philo_life(philo[i]);
// 			exit(0);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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

// int	ft_init_phils(t_sets *settings)
// {
// 	t_phs	**philo;

// 	philo = malloc(sizeof(t_phs *) * settings->philos_count);
// 	if (!philo)
// 		return (MALERR);
// 	ft_init_sem(settings);
// 	if (ft_make_all_phils(settings, philo))
// 		return (PHIERR);
// 	if (ft_wait_and_kill(settings, philo))
// 		return (SIGERR);
// 	free(philo);
// 	return (0);
// }
