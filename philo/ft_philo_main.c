/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/25 15:31:01 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sets	settings;

	if (argc <= 4 || argc >= 7)
	{
		printf("Check arguments quantity and try again\n");
		return (0);
	}
	printf("Arguments quantity is correct\n");
	if ((ft_init_settings(argc, argv, &settings)) == NULL)
		return (1);
	// get start time
	settings.time = ft_get_time_ms();
	printf("START time is %lu\n", (ft_get_time_ms() - settings.time));
	if ((ft_init_phils(settings)))
		return (1);
	// create array of philosophers, assign ordered forks to the philofophers
	// create array of mutexes, associate each mutex to each philosopher
	// create thread called waiter
	// ft_prepare_simulation(&settings);
	return (0);
}
