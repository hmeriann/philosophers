/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/11 19:59:04 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_inits(t_sets *settings, t_phs *phils)
{
	int	err_code;

	err_code = 0;
	if (init_pid(&settings))
		return (err_code = PIDERR);
	if (init_phils(&settings, &phils))
		return (err_code = PHIERR);
	if (init_sems(&settings))
		return (err_code = SEMERR);
	return (err_code);
}

int	ft_inits_ph(t_sets *settings)
{
	t_phs	**phils;
	int		i;
	int		j;
	int		status;
	int		pid;

	i = 0;
	phils = malloc(sizeof(t_phs *) * settings->philos_count);
	ft_sem_init(settings);
	while (i < settings->philos_count)
	{
		pid = fork();
		if (pid < 0)
			return (FORERR);
		settings->time = ft_get_time_ms_bonus();
		phils[i] = malloc(sizeof(t_phs) * settings->philos_count);
		phils[i]->pid = pid;
		if (!pid)
		{
			phils[i]->pos_in_arr = i;
			phils[i]->pos_in_arr = i;
			phils[i]->fork = settings->forks;
			phils[i]->settings = settings;
			if (settings->should_eat_times)
				phils[i]->already_ate = 0;
			ft_philo_life(phils[i]);
			exit(0);
		}
		i++;
	}
	i = 0;
	j = 0;
	while (j < settings->philos_count)
	{
		if (waitpid(-1, &status, 0) < 0)
			return (SIGERR);
		if (WIFEXITED(status) == 1)
		{
			while (i < settings->philos_count)
			{
				kill(phils[i]->pid, SIGKILL);
				i++;
			}
		j++;
		}
	}
	free(phils);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sets	settings;
	int		err_code;

	err_code = -1;
	if (argc <= 4 || argc >= 7)
		return (ft_print_err_bonus(err_code));
	err_code = ft_save_settings_bonus(argc, argv, &settings);
	if (err_code)
		return (ft_print_err_bonus(err_code));
	err_code = ft_inits_ph(&settings);
	if (err_code)
		return (ft_print_err_bonus(err_code));
	err_code = ft_start_process(&settings);
	if (err_code)
		return (ft_print_err_bonus(err_code));
	sem_wait(settings.check_dead);
	settings.isdead = 1;
	ft_destroy_sem(&settings);
	return (0);
}
