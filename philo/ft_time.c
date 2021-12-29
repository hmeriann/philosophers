/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:20:49 by zu                #+#    #+#             */
/*   Updated: 2021/12/29 18:48:15 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_make_time_to_eat_ms(int time)
{
	long	goal_time;
	long	curr_time;

	curr_time = ft_get_time_ms();
	goal_time = ft_get_time_ms() + (long)time;
	while (curr_time < goal_time)
	{
		usleep(50);
		curr_time = ft_get_time_ms();
	}
}
