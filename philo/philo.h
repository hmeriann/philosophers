/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:19 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/19 15:43:42 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

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
	int		eatings_count;
	t_phs	*philo;
}	t_sets;

int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_csearch(char *haystack, char needle, size_t len);
int		check_numeric(char **argv);
t_sets	*ft_init_settings(int argc, char **argv, t_sets *table);
void	ft_prepare_simulation(t_sets *table);

#endif
