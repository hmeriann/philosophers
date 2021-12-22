/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2021/12/22 18:05:45 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
initialize philosophers structure
allocate memory for array of philosophers
give their forks an order
*/

void	ft_prepare_simulation(t_sets *cond)
{
	int		i;
	t_phs	table;

	i = 1;
	while (i <= cond->philo_count)
	{
		table.order = i;
		// table.left_fork = i;
		printf("philo #%d\n", table.order);
		i++;
	}
}
