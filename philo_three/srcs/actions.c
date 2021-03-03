/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:58:35 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/03 15:50:26 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philthree.h"

int			is_alive(t_philos *p)
{
	double	deadtime;

	sem_wait(p->mutex);
	deadtime = p->deadtime;
	if (deadtime == -1)
	{
		sem_post(p->mutex);
		return (1);
	}
	if (!check_time(deadtime, get_p(NULL)))
	{
		sem_post(p->mutex);
		return (0);
	}
	sem_post(p->mutex);
	return (1);
}

static void	sleeping(t_philos *p)
{
	sem_wait(p->mutex);
	if (is_alive(p))
		print_action(p, "is sleeping");
	usleep(get_p(NULL)->tts * 1000);
	sem_post(p->mutex);
}

static void	try_to_eat(t_philos *p)
{
	sem_wait(p->mutex);
	sem_wait(get_p(NULL)->forks);
	print_action(p, "has taken a fork");
	sem_wait(get_p(NULL)->forks);
	print_action(p, "has taken a fork");
	p->eat -= 1;
	print_action(p, "eat");
	p->deadtime = get_time(get_p(NULL)) + get_p(NULL)->ttd;
	usleep(get_p(NULL)->tte * 1000);
	sem_post(get_p(NULL)->forks);
	sem_post(get_p(NULL)->forks);
	sem_post(p->mutex);
}

void		*while_alive(void *p)
{
	while (1)
		if (!is_alive(p))
			exit(1);
		else if (!((t_philos *)p)->eat)
			break ;
	return (NULL);
}

void		*simulate(void *philo)
{
	t_philos	**p;

	p = philo;
	pthread_create(&(*p)->thread, NULL, while_alive, (*p));
	pthread_detach((*p)->thread);
	pthread_join((*p)->thread, NULL);
	while ((*p)->eat != 0)
	{
		print_action(*p, "is thinking");
		try_to_eat(*p);
		if ((*p)->eat)
			sleeping(*p);
	}
	(*p)->deadtime = -1;
	exit(0);
	return (philo);
}
