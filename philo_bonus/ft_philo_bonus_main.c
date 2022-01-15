/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/15 18:08:27 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_one_ph(t_sets *settings, t_phs *phils, int i)
{
	phils->pos_in_arr = i;
	phils->settings = settings;
	phils->time_to_be_hungry = settings->time;
	if (settings->should_eat_times)
		phils->already_ate = 0;
}

void	ft_philo_init(t_sets *settings, t_phs *phils)
{
	int	i;

	i = 0;
	settings->time = ft_get_time_ms_bonus();
	while (i < settings->philos_count)
	{
		phils[i].pos_in_arr = i;
		phils[i].settings = settings;
		phils[i].time_to_be_hungry = settings->time;
		if (settings->should_eat_times)
			phils[i].already_ate = 0;
		i++;
	}
}

int	ft_make_philos(t_sets *settings, t_phs *phils)
{
	int	i;

	i = 0;
	while (i < settings->philos_count)
	{
		phils[i].pid = fork();
		if (phils[i].pid < 0)
			return (FORERR);
		if (!phils[i].pid)
		{
			ft_philo_life(&phils[i]);
			exit(0);
		}
		i++;
	}
	return (0);
}

int	ft_inits_ph(t_sets *settings)
{
	t_phs	*phils;
	int		j;
	int		status;

	j = 0;
	phils = malloc(sizeof(t_phs) * settings->philos_count);
	ft_init_sem(settings);
	ft_philo_init(settings, phils);
	ft_make_philos(settings, phils);
	ft_wait_and_kill(settings, phils);
	sem_close(settings->print);
	sem_close(settings->forks);
	sem_close(settings->check_dead);
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
	return (0);
}
