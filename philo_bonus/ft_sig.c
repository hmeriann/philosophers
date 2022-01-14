/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:22:26 by zu                #+#    #+#             */
/*   Updated: 2022/01/12 14:42:32 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// int	ft_init_pid(t_sets *settings)
// {
// 	int	i;

// 	i = 0;
// 	settings->pid = (int *)malloc(sizeof(int) * settings->philos_count);
// 	if (!settings->pid)
// 		return (MALERR);
// 	while (i < settings->philos_count)
// 	{
// 		settings->pid[i] = 0;
// 		i++;
// 	}
// 	return (0);
// }

int	ft_wait_and_kill(t_sets *settings, t_phs **philo)
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
				kill(philo[j]->pid, SIGKILL);
				j++;
			}
		}
		i++;
	}
	return (0);
}
