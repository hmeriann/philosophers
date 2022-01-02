/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phil_eats.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 20:49:21 by zu                #+#    #+#             */
/*   Updated: 2022/01/02 21:18:38 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_phil_eats(t_phs	*curr_phil)
{
	ft_print_state(curr_phil, 1);
	ft_print_state(curr_phil, 1);
	ft_print_state(curr_phil, 2);
	ft_my_sleep_ms(curr_phil->settings->time_to_eat);
}
