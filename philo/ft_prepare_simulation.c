/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_simulation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:51:28 by zu                #+#    #+#             */
/*   Updated: 2021/12/25 15:37:33 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
initialize philosophers structure
allocate memory for array of philosophers
give their forks an order
*/

int	ft_init_phils(t_sets settings)
{
	t_phs	*philos;
	int		i;

	philos = (t_phs *)malloc(sizeof(t_phs) * settings.philos_count);
	if (!(philos))
		return (1);
	i = 0;
	while (i < settings.philos_count)
	{
		philos[i].order = i;
		philos[i].order_r_fork = i;
		philos[i].order_l_fork = (i + 1) % settings.philos_count;
		philos[i].already_ate = 0;
		printf("philo #%d: order left fork = %d, order right fork = %d\n", philos[i].order, philos[i].order_l_fork, philos[i].order_r_fork);
		i++;
	}
	return (0);
}

void	ft_prepare_simulation(t_sets *settings)
{
	int		i;

	i = 1;
	while (i <= settings->philos_count)
	{
		// table.order = i;
		// table.left_fork = i;
		// printf("philo #%d: order left fork = %d, order right fork = %d\n", table.order, table.order_l_fork, table.order_r_fork);
		i++;
	}
}
