/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:58:25 by hmeriann          #+#    #+#             */
/*   Updated: 2021/12/19 15:00:58 by hmeriann         ###   ########.fr       */
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

void	ft_check_args(int argc, char **argv, t_sets *cond)
{
	if (check_numeric(argv))
		printf("Conditions should be only numeric\n");
	else
	{
		cond->philo_count = ft_atoi(argv[1]);
		cond->time_to_die = ft_atoi(argv[2]);
		cond->time_to_eat = ft_atoi(argv[3]);
		cond->time_to_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			cond->eatings_count = ft_atoi(argv[5]);
		else
			cond->eatings_count = -1;
		printf("philo_count = %d, time_to_die = %d, time_to_eat = %d, time_to_sleep = %d, eatings = %d\n", cond->philo_count, cond->time_to_die, cond->time_to_eat, cond->time_to_sleep, cond->eatings_count);
	}
}
