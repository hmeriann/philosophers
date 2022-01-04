/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmeriann <hmeriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:35:42 by hmeriann          #+#    #+#             */
/*   Updated: 2022/01/04 16:03:07 by hmeriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print_err(int err_code)
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
	return (err_code);
}
