/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:19 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/02 23:21:39 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5

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
	int				last_eat_time;
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
	pthread_mutex_t	*print;
	int				simulation_end;
	int				did_eat_times;
	int				time;
}	t_sets;

int		ft_atoi(const char *str);
size_t	ft_strlen(char *str);
int		ft_csearch(char *haystack, char needle, size_t len);
int		check_numeric(char **argv);
int		ft_save_settings(int argc, char **argv, t_sets *table);
void	ft_prepare_simulation(t_sets *table);
int		ft_get_time_ms(void);
int		ft_init_phils(t_sets *settings, t_phs *phils);
int		ft_init_forks(t_sets *settings, t_phs *phils);
int		ft_phils_threads(t_sets *settings, t_phs *phils);
void	ft_my_sleep_ms(int time);
void	ft_exit(int ret, t_phs *phils);
void	ft_print_state(t_phs *curr_phil, int state);
void	ft_phil_eats(t_phs	*curr_phil);
int		ft_forks_destroy(t_sets	*settings);
int		ft_watcher(t_phs *phils);
void	*ft_watching(void *phil);

#endif
