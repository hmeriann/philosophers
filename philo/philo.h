/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:19 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/29 18:48:24 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_phs
{
	int				pos_in_arr;
	int				order;
	int				order_l_fork;
	int				order_r_fork;
	int				already_ate;
	pthread_mutex_t	*mutex_left_f;
	pthread_mutex_t	*mutex_right_f;
	pthread_t		*phils_thread;
	long			last_eat_time;
	struct s_sets	*settings;
}	t_phs;

typedef struct s_sets
{
	int				philos_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				should_eat_times;
	t_phs			*philo;
	pthread_mutex_t	*forks;
	int				simulation_end;
	int				did_eat_times;
	long			time;
}	t_sets;

int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_csearch(char *haystack, char needle, size_t len);
int		check_numeric(char **argv);
t_sets	*ft_save_settings(int argc, char **argv, t_sets *table);
void	ft_prepare_simulation(t_sets *table);
long	ft_get_time_ms(void);
int		ft_init_phils(t_sets *settings, t_phs *phils);
int		ft_init_forks(t_sets *settings, t_phs *phils);
int		ft_phils_threads(t_sets *settings, t_phs *phils);
void	ft_make_time_to_eat_ms(int time);

#endif
