/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:33:57 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/11 18:21:47 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus/philo_bonus.h"

int	init_pid(t_sets *settings)
{
	int	i;

	i = 0;
	settings->pid = (int *)malloc(sizeof(int) * settings->philos_count);
	if (!settings->pid)
		return (MALERR);
	while (i < settings->philos_count)
	{
		settings->pid[i] = 0;
		i++;
	}
	return (0);
}

int	init_phils(t_sets *settings)
{

}
