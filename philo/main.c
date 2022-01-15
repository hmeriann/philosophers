/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:58:24 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/15 16:21:03 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_forks_destroy(t_sets	*settings)
{
	int	i;
    int err_code;

    i = 0;
    err_code = 0;
	while (i < settings->philos_count) {
        free(&settings->forks[i]);
        err_code = pthread_mutex_destroy(&(settings->forks[i]));
        if (!err_code)
            return (err_code);
    }
	free(settings->print);
	err_code = pthread_mutex_destroy(settings->print);
    if (!err_code)
        return (err_code);
    free(settings->forks);
    err_code = pthread_mutex_destroy(settings->forks);
    if (!err_code)
        return (err_code);
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
    err_code = ft_forks_destroy(&settings);
    free(settings.phs_threads);
    if (!err_code)
        return (err_code);
    return (0);
}
