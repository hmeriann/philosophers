/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inits_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:33:57 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/14 21:09:58 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_sem(t_sets *settings)
{
	sem_unlink("fork");
	sem_unlink("print");
	sem_unlink("death");
	settings->forks = sem_open("fork", O_CREAT, 0777, settings->philos_count);
	settings->print = sem_open("print", O_CREAT, 0777, 1);
	settings->check_dead = sem_open("death", O_CREAT, 0777, 1);
}
