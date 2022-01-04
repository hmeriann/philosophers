/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/04 16:23:54 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(int ret, t_phs *phils)
{
	if (ret == 1)
		free(phils);
}

int	ft_forks_destroy(t_sets	*settings)
{
	int	i;

	i = 0;
	while (i < settings->philos_count)
		pthread_mutex_destroy(&(settings->forks[i]));
	free(settings->print);
	pthread_mutex_destroy(settings->print);
	printf("destroy\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_sets	settings;
	t_phs	*phils;
	int		err_code;

	err_code = -1;
	if (argc <= 4 || argc >= 7)
		return (ft_print_err(err_code));
	err_code = ft_save_settings(argc, argv, &settings);
	if (err_code)
		return (ft_print_err(err_code));
	phils = malloc(sizeof(t_phs) * settings.philos_count);
	if (!phils)
		return (ft_print_err(MALERR));
	err_code = ft_init_phils(&settings, phils);
	if (err_code)
		return (ft_print_err(PHIERR));
	err_code = ft_init_forks(&settings, phils);
	if (err_code)
		return (ft_print_err(err_code));
	err_code = ft_at_the_table(&settings, phils);
	if (err_code)
		return (ft_print_err(err_code));
	return (0);
}
