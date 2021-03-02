/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/02 10:52:37 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

int			check_time(double time, t_params *p)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	if (time >= get_time(p) - 2)
		return (1);
	return (0);
}

void		check_life(t_params *p)
{
	int i;
	int	j;

	while (1)
	{
		i = -1;
		j = 0;
		while (++i < p->nphils)
		{
			if (!p->philo[i]->eat)
				j++;
			if (j == p->nphils)
				return ;
			if (!is_alive(p->philo[i]))
			{
				print_action(p->philo[i], "died");
				pthread_mutex_lock(&p->mutex);
				return ;
			}
		}
	}
}

int			main(int ac, char **av)
{
	t_params	*p;
	int			i;

	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !", NULL));
	if (!(p = init_params(0, ac, av)))
		return (print_error("Malloc error !", NULL));
	if (p->error)
		return (print_error("Invalid(s) parameter(s) !", p));
	init_philos(p);
	check_life(p);
	i = -1;
	while (++i < p->nphils)
	{
		pthread_detach(p->philo[i]->thread);
		pthread_mutex_destroy(p->fork[i]);
		free(p->philo[i]);
	}
	pthread_mutex_destroy(&p->mutex);
	free(p->fork);
	free(p->philo);
	free(p);
	return (0);
}
