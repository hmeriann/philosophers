/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:20:49 by zu                #+#    #+#             */
/*   Updated: 2022/01/15 17:57:50 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_get_time_ms(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_my_sleep_ms(int time)
{
	int	goal_time;
	int	curr_time;

	curr_time = ft_get_time_ms();
	goal_time = ft_get_time_ms() + time;
	while (curr_time < goal_time)
	{
		usleep(100);
		curr_time = ft_get_time_ms();
	}
}
