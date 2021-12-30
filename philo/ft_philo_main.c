/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:06:48 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/30 19:58:54 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(int ret, t_phs *phils)
{
	if (ret == 1)
		free(phils);
}

int	main(int argc, char **argv)
{
	t_sets			settings;
	t_phs			*phils;

	if (argc <= 4 || argc >= 7)
	{
		printf("Check arguments quantity and try again\n");
		return (1);
	}
	if (ft_save_settings(argc, argv, &settings))
		return (1);
	phils = malloc(sizeof(t_phs) * settings.philos_count);
	if (!phils)
		return (1);
	if (ft_init_phils(&settings, phils))
		return (1);
	if (ft_init_forks(&settings, phils))
		ft_exit(1, phils);
	if (ft_phils_threads(&settings, phils))
		ft_exit(1, phils);
	return (0);
}
