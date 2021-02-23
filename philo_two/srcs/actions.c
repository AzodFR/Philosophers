/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:58:35 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/23 15:18:03 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philtwo.h"

int		is_alive(t_philos *p)
{
	if (p->deadtime == -1)
		return (1);
	if (!check_time(p->deadtime, p->p))
		return (0);
	return (1);
}

void	sleeping(t_philos *p)
{
	//sem_wait(p->mutex);
	if (is_alive(p))
		print_action(p, "is sleeping");
	usleep(p->p->tts * 1000);
	//sem_post(p->mutex);
}

void	try_to_eat(t_philos *p)
{
	struct timeval	actual;

	sem_wait(p->mutex);
	sem_wait(p->p->forks);
	print_action(p, "has taken a fork");
	sem_wait(p->p->forks);
	print_action(p, "has taken a fork");
	print_action(p, "eat");
	gettimeofday(&actual, NULL);
	p->deadtime = get_time(p->p) + p->p->ttd;
	usleep(p->p->tte * 1000);
	gettimeofday(&actual, NULL);
	p->deadtime = get_time(p->p) + p->p->ttd;
	p->eat -= 1;
	sem_post(p->p->forks);
	sem_post(p->p->forks);
	sem_post(p->mutex);
}

void	*simulate(void *philo)
{
	t_philos	**p;
	t_params	*prog;

	p = philo;
	prog = (*p)->p;
	while (!prog->end && (*p)->eat != 0)
	{
		print_action(*p, "is thinking");
		try_to_eat(*p);
		if ((*p)->eat)
			sleeping(*p);
	}
	if (!prog->end)
		(*p)->deadtime = -1;
	return (philo);
}
