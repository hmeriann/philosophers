/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:19 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/04 16:40:29 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define FORK	1
# define EAT	2
# define SLEEP	3
# define THINK	4
# define DIE	5
# define ARGERR	-1
# define UNSERR	-2
# define ZERERR	-3
# define MUTERR	-4
# define MALERR	-5
# define PHIERR	-6
# define FORERR	-7
# define THRERR	-8

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
	pthread_t		*phs_threads;
}	t_sets;

int		ft_atoi_bonus(const char *str);
int		ft_print_err_bonus(int err_code);
size_t	ft_strlen_bonus(char *str);
int		ft_csearch_bonus(char *haystack, char needle, size_t len);
int		check_numeric_bonus(char **argv);
int		ft_save_settings_bonus(int argc, char **argv, t_sets *table);
void	ft_prepare_simulation_bonus(t_sets *table);
int		ft_get_time_ms_bonus(void);
int		ft_init_phils_bonus(t_sets *settings, t_phs *phils);
int		ft_init_forks_bonus(t_sets *settings, t_phs *phils);
int		ft_at_the_table_bonus(t_sets *settings, t_phs *phils);
void	ft_my_sleep_ms_bonus(int time);
void	ft_print_state_bonus(t_phs *curr_phil, int state);
void	ft_phil_eats_bonus(t_phs	*curr_phil);
int		ft_forks_destroy_bonus(t_sets	*settings);
int		ft_watcher_bonus(t_phs *phils);
void	*ft_watching_bonus(void *phil);

#endif
