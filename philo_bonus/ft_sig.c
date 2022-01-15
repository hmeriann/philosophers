/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:22:26 by zu                #+#    #+#             */
/*   Updated: 2022/01/14 21:11:11 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_wait_and_kill(t_sets *settings, t_phs *philo)
{
	int	i;
	int	j;
	int	status;

	i = 0;
	while (i < settings->philos_count)
	{
		if (waitpid(-1, &status, 0) < 0)
			return (PIDERR);
		if (WIFEXITED(status) == 1)
		{
			j = 0;
			while (j < settings->philos_count)
			{
				kill(philo[j].pid, SIGKILL);
				j++;
			}
		}
		i++;
	}
	return (0);
}
