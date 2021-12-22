/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/22 18:03:47 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_sets	settings;

	if (argc <= 4 || argc >= 7)
		printf("Check conditions quantity and try again\n");
	else
	{
		printf("Conditions quantity is correct\n");
		if ((ft_init_settings(argc, argv, &settings)) == NULL)
			return (1);
		// get start time
		// create array of philosophers, assign ordered forks to the philofophers
		// create array of mutexes, associate each mutex to each philosopher
		// create thread called waiter
		ft_prepare_simulation(&settings);
	}
	return (0);
}
