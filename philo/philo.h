/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:19 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/23 23:39:41 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_phs
{
	int				order;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_phs;

typedef struct s_sets
{
	int		philo_count;
	int		forks_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		should_eat_times;
	t_phs	*philo;
	int		simulation_end;
	int		did_eat_times;
}	t_sets;

int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_csearch(char *haystack, char needle, size_t len);
int		check_numeric(char **argv);
t_sets	*ft_init_settings(int argc, char **argv, t_sets *table);
void	ft_prepare_simulation(t_sets *table);
long	ft_get_time_ms(void);

#endif
