/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/23 15:15:10 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philtwo.h"

int			check_time(int time, t_params *p)
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
				p->end = 1;
				print_action(p->philo[i], "died");
				return ;
			}
		}
	}
}

void		unlink_sem(void)
{
	sem_unlink("main");
	sem_unlink("forks");
	sem_unlink("philo");
}

int			main(int ac, char **av)
{
	t_params	*p;
	int			i;

	unlink_sem();
	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !", NULL));
	if (!(p = init_params(0, ac, av)))
		return (print_error("Malloc error !", NULL));
	if (p->error)
		return (print_error("Invalid(s) parameter(s) !", p));
	p->end = 0;
	init_philos(p);
	check_life(p);
	i = -1;
	while (++i < p->nphils)
	{
		pthread_detach(p->philo[i]->thread);
		sem_close(p->philo[i]->mutex);
		free(p->philo[i]);
	}
	sem_close(p->mutex);
	sem_close(p->forks);
	unlink_sem();
	free(p->philo);
	free(p);
	return (0);
}
