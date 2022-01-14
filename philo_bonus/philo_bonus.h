/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:59:19 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/13 19:02:08 by zu               ###   ########.fr       */
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
# define SEMERR	-9
# define PIDERR	-10
# define SIGERR	-11
# define SEMFORK	"sem_fork"
# define SEMEAT		"sem_eat"
# define SEMPRINT	"sem_print"
# define SEMDEAD	"sem_dead"

typedef struct s_phs
{
	int				pos_in_arr;
	int				order;
	int				pid;
	int				already_ate;
	int				last_eat_time;
	int				time_to_be_hungry;
	// sem_t			*fork;
	struct s_sets	*settings;
}	t_phs;

typedef struct s_sets
{
	int		philos_count;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		should_eat_times;
	int		simulation_end;
	int		did_eat_times;
	int		time;
	int		stop_flag;
	int		*pid;
	int		isdead;
	// t_phs	*philo;
	sem_t	*forks;
	sem_t	*print;
	sem_t	*check_dead;
	sem_t	*taking;
}	t_sets;

int		ft_make_all_phils(t_sets *settings, t_phs **philo);
void	ft_init_sem(t_sets *settings);
int		ft_init_phils(t_sets *settings);
int		ft_inits(t_sets *settings, t_phs *phils);
int		ft_init_ph(t_sets *settings);
void	ft_init_one_ph(t_sets *settings, t_phs *phils, int i);
int		ft_make_philos(t_sets *settings, t_phs *phils);
int		ft_inits_ph(t_sets *settings);
void	ft_take_forks_and_eat(t_phs *phil);
void	*ft_philo_life(void	*philo);
int		ft_print_err_bonus(int err_code);
void	ft_print_state_bonus(t_phs *curr_phil, int state);
int		ft_csearch_bonus(char *haystack, char needle, size_t len);
int		check_numeric_bonus(char **argv);
int		ft_save_settings_bonus(int argc, char **argv, t_sets *table);
int		ft_wait_and_kill(t_sets *settings, t_phs **philo);
int		ft_get_time_ms_bonus(void);
void	ft_my_sleep_ms_bonus(int time);
int		ft_watch_bns(t_phs *phil);
void	*check_if_dead(void *phils);
int		ft_atoi_bonus(const char *str);
size_t	ft_strlen_bonus(char *str);

#endif
