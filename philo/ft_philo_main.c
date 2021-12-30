/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/30 19:03:08 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sets			settings;
	t_phs			*phils;

	if (argc <= 4 || argc >= 7)
	{
		printf("Check arguments quantity and try again\n");
		return (0);
	}
	printf("Arguments quantity is correct\n");
	if (ft_save_settings(argc, argv, &settings))
		return (1);
	// create array of philosophers, assign ordered forks to the philofophers
	phils = malloc(sizeof(t_phs) * settings.philos_count);
	if (!phils)
		return (1);
	if (ft_init_phils(&settings, phils))
		return (1);
	// create array of mutexes, associate each mutex to each philosopher
	if (ft_init_forks(&settings, phils))
	{
		free(phils);
		return (1);
	}
	//create phils threads
	if (ft_phils_threads(&settings, phils))
	{
		free(phils);
		return (1);
	}
	// create thread called waiter
	return (0);
}
