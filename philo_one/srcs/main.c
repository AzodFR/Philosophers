/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/19 15:59:58 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

int			check_time(int	time, t_params *p)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	if (time >= get_time(p))
		return (1);
	return (0);
}

void		check_life(t_params *p)
{
	int i;

	while (1)
	{
		i = -1;
		while (++i < p->nphils)
		{
			if (!is_alive(p->philo[i]))
			{
				print_action(p->philo[i], "died");
				return ;
			}
		}
	}
}

int		main(int ac, char **av)
{
	t_params *p;
	int		i;
	p = init_params(ac, av);
	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !", p));
	print_params(p);
	init_philos(p);
	check_life(p);
	i = -1;
	while (++i < p->nphils)
	{
		pthread_mutex_destroy(p->fork[i]);
		free(p->philo[i]);
	}
	free(p->fork);
	free(p->philo);
	free(p);
	return (0);
}