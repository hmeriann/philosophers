/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/02 21:19:30 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(int ret, t_phs *phils)
{
	if (ret == 1)
		free(phils);
}

int	ft_forks_destroy(t_sets	*settings)
{
	int	i;

	i = 0;
	while (i < settings->philos_count)
		pthread_mutex_destroy(&(settings->forks[i]));
	free(settings->print);
	pthread_mutex_destroy(settings->print);
	printf("destroy\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_sets			settings;
	t_phs			*phils;

	if (argc <= 4 || argc >= 7)
	{
		printf("Check arguments quantity and try again\n");
		return (1);
	}
	if (ft_save_settings(argc, argv, &settings))
		return (1);
	phils = malloc(sizeof(t_phs) * settings.philos_count);
	if (!phils)
		return (1);
	if (ft_init_phils(&settings, phils))
		return (1);
	if (ft_init_forks(&settings, phils))
		ft_exit(1, phils);
	if (ft_phils_threads(&settings, phils))
		ft_exit(1, phils);
	return (0);
}
