/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zu <zu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:58:25 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/28 10:24:13 by zu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_csearch(char *haystack, char needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (needle == '\0')
		return (0);
	i = 0;
	k = 0;
	j = ft_strlen(haystack);
	while (k < len)
	{
		while (haystack[i] != needle && haystack[i] != '\0')
			i++;
		k++;
	}
	if (j <= i)
		return (1);
	else
		return (0);
}

int	check_numeric(char **argv)
{
	int		i;
	int		j;
	size_t	len;

	i = 1;
	while (argv[i])
	{
		j = 0;
		len = ft_strlen(argv[i]);
		while (argv[i][j] != '\0')
		{
			if (ft_csearch("0123456789", argv[i][j], len))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_sets	*ft_save_settings(int argc, char **argv, t_sets *settings)
{
	if (check_numeric(argv))
	{
		printf("Conditions should be only unsigned int\n");
		return (NULL);
	}
	else
	{
		settings->philos_count = ft_atoi(argv[1]);
		if (settings->philos_count == 0)
		{
			printf("There should be at least one philosopher.\n");
			return (NULL);
		}
		settings->time_to_die = ft_atoi(argv[2]);
		settings->time_to_eat = ft_atoi(argv[3]);
		settings->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
		{
			settings->should_eat_times = ft_atoi(argv[5]);
			if (settings->should_eat_times == 0)
			{
				printf("Eatings quantity should be more than 0.\n");
				return (NULL);
			}
		}
		else
			settings->should_eat_times = -1;
		settings->time = ft_get_time_ms();
		return (settings);
	}
}
