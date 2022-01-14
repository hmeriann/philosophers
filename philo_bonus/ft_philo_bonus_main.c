/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_bonus_main.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/14 17:53:51 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_all_ph(t_sets *settings, t_phs *phils)
{
	int	i;

	i = 0;
	settings->time = ft_get_time_ms_bonus();
	while (i < settings->philos_count)
	{
		phils[i].pos_in_arr = i;
		phils[i].pos_in_arr = i;
		phils[i].settings = settings;
		phils[i].time_to_be_hungry = settings->time;
		if (!settings->should_eat_times)
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

int	ft_start_all(t_sets *settings, t_phs *phils)
{
	int		j;
	int		status;
	int		err_code;

	j = 0;
	ft_init_all_ph(settings, phils);
	ft_init_sem(settings);
	err_code = ft_make_philos(settings, phils);
	if (err_code)
		return (err_code);
	2  потока мониторинга всего остального, а в потоке проверялка количества трапез и смерти

	семафор на конец симуляции на 0
	err_code = ft_wait_and_kill(settings, phils);
	if (err_code)
		return (err_code);
	sem_close(settings->print);
	sem_close(settings->check_dead);
	sem_close(settings->forks);
	free(phils);
	return (0);
}

int	main(int argc, char **argv)
{
	t_phs	*phils;
	t_sets	settings;
	int		err_code;

	err_code = -1;
	if (argc <= 4 || argc >= 7)
		return (ft_print_err_bonus(err_code));
	err_code = ft_save_settings_bonus(argc, argv, &settings);
	if (err_code)
		return (ft_print_err_bonus(err_code));
	phils = malloc(sizeof(t_phs) * settings.philos_count);
	if (!phils)
		return (ft_print_err_bonus(MALERR));
	err_code = ft_start_all(&settings, phils);
	if (err_code)
		return (ft_print_err_bonus(err_code));
	return (0);
}
