/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:13:32 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/19 15:54:20 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

t_params	*init_params(int ac, char **av)
{
	t_params	*p;
	int			i;

	if (!(p = malloc(sizeof(t_params))))
		return (NULL);
	gettimeofday(&p->start, NULL);
	if (ac < 5 || ac > 6)
		return (p);
	p->nphils = ft_atoi(av[1]);
	if (!(p->philo = malloc(p->nphils * sizeof(t_philos*))))
		return (NULL);
	if (!(p->fork = malloc(p->nphils * sizeof(pthread_mutex_t *))))
		return (NULL);
	p->ttd = ft_atoi(av[2]);
	p->tte = ft_atoi(av[3]);
	p->tts = ft_atoi(av[4]);
	p->dead = -1;
	if (ac < 6)
		p->noe = -1;
	else
		p->noe = ft_atoi(av[5]);
		i = -1;
	while (++i < p->nphils)
	{
		p->fork[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(p->fork[i], NULL);
	}
	return (p);
}

void	init_philos(t_params *p)
{
	struct timeval	actual;
	int		i;

	i = -1;
	while (++i < p->nphils)
	{
		p->philo[i] = malloc(sizeof(t_philos));
		p->philo[i]->id = i;
		p->philo[i]->eat = p->noe;
		p->philo[i]->p = p;
		gettimeofday(&actual, NULL);
		p->philo[i]->deadtime = (get_time(p)) + p->ttd;
		pthread_mutex_init(&(p->philo[i]->mutex), NULL);
		pthread_create(&p->philo[i]->thread, NULL, simulate, &p->philo[i]);
		pthread_detach(p->philo[i]->thread);
		pthread_join(p->philo[i]->thread, NULL);
		usleep(5000);
	}

}