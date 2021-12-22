/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:58:25 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/22 18:00:10 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_sets	*ft_init_settings(int argc, char **argv, t_sets *settings)
{
	if (check_numeric(argv))
	{
		printf("Conditions should be only numeric\n");
		return (NULL);
	}
	else
	{
		settings->philo_count = ft_atoi(argv[1]);
		if (settings->philo_count == 0)
		{
			printf("There should be at least one philosopher.\n");
			return (NULL);
		}
		settings->forks_count = settings->philo_count;
		settings->time_to_die = ft_atoi(argv[2]);
		settings->time_to_eat = ft_atoi(argv[3]);
		settings->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			settings->eatings_count = ft_atoi(argv[5]);
		else
			settings->eatings_count = -1;
		printf("philo_count = %d, time_to_die = %d, time_to_eat = %d, time_to_sleep = %d, eatings = %d\n", settings->philo_count, settings->time_to_die, settings->time_to_eat, settings->time_to_sleep, settings->eatings_count);
		return (settings);
	}
}
