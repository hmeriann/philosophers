/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:58:25 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/19 15:03:14 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_sets	*ft_init_settings(int argc, char **argv, t_sets *table)
{
	if (check_numeric(argv))
	{
		printf("Conditions should be only numeric\n");
		return (NULL);
	}
	else
	{
		table->philo_count = ft_atoi(argv[1]);
		if (table->philo_count == 0)
		{
			printf("There should be at least one philosopher.\n");
			return (NULL);
		}
		table->forks_count = table->philo_count;
		table->time_to_die = ft_atoi(argv[2]);
		table->time_to_eat = ft_atoi(argv[3]);
		table->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			table->eatings_count = ft_atoi(argv[5]);
		else
			table->eatings_count = -1;
		printf("philo_count = %d, time_to_die = %d, time_to_eat = %d, time_to_sleep = %d, eatings = %d\n", table->philo_count, table->time_to_die, table->time_to_eat, table->time_to_sleep, table->eatings_count);
		return (table);
	}
}
