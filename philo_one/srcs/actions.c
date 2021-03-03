/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:58:35 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/03 12:04:14 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

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
	pthread_mutex_lock(&(p->mutex));
	if (is_alive(p))
		print_action(p, "is sleeping");
	usleep(p->p->tts * 1000);
	pthread_mutex_unlock(&(p->mutex));
}

void	try_to_eat(t_philos *p)
{
	pthread_mutex_lock(&(p->mutex));
	pthread_mutex_lock(p->p->fork[p->id]);
	print_action(p, "has taken a fork");
	pthread_mutex_lock(p->p->fork[(p->id + 1) % p->p->nphils]);
	print_action(p, "has taken a fork");
	print_action(p, "eat");
	p->deadtime = get_time(p->p) + p->p->ttd;
	usleep(p->p->tte * 1000);
	p->eat -= 1;
	pthread_mutex_unlock(p->p->fork[p->id]);
	pthread_mutex_unlock(p->p->fork[(p->id + 1) % p->p->nphils]);
	pthread_mutex_unlock(&(p->mutex));
}

void	*simulate(void *philo)
{
	t_philos	**p;

	p = philo;
	while ((*p)->eat != 0)
	{
		print_action(*p, "is thinking");
		try_to_eat(*p);
		if ((*p)->eat)
			sleeping(*p);
	}
	(*p)->deadtime = -1;
	return (philo);
}
