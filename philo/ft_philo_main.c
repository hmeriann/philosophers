/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/19 14:49:06 by hmeriann         ###   ########.fr       */
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
			return (0);
		// create the struct of a phils and give an order# to each of phils
		ft_prepare_simulation(&settings);
	}
	return (0);
}
