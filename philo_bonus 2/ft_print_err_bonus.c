/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:35:42 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/11 19:57:50 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_print_err_bonus(int err_code)
{
	if (err_code == ARGERR)
		write(2, "Check arguments quantity and try again\n", 39);
	else if (err_code == UNSERR)
		write(2, "Arguments should be only unsigned int\n", 38);
	else if (err_code == ZERERR)
		write(2, "Arguments should be more than zero\n", 35);
	else if (err_code == MALERR)
		write(2, "Malloc error\n", 13);
	else if (err_code == PHIERR)
		write(2, "Phils init error\n", 17);
	else if (err_code == FORERR)
		write(2, "Forks init error\n", 17);
	else if (err_code == THRERR)
		write(2, "Thread error\n", 13);
	else if (err_code == MUTERR)
		write(2, "Mutex error\n", 12);
	else if (err_code == SIGERR)
		write(2, "Signal error\n", 13);
	exit(1);
}
