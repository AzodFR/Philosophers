/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:13:32 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/01 17:30:37 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

t_params		*init_forks(int i, t_params *p)
{
	while (++i < p->nphils)
	{
		if (!(p->fork[i] = malloc(sizeof(pthread_mutex_t))))
			return (NULL);
		pthread_mutex_init(p->fork[i], NULL);
	}
	return (p);
}

t_params		*init_params(int i, int ac, char **av)
{
	t_params	*p;

	if (!(p = malloc(sizeof(t_params))))
		return (NULL);
	gettimeofday(&p->start, NULL);
	p->error = 0;
	p->nphils = ft_atoi(av[1]);
	if (!(p->philo = malloc(p->nphils * sizeof(t_philos*))))
		return (NULL);
	if (!(p->fork = malloc(p->nphils * sizeof(pthread_mutex_t *))))
		return (NULL);
	if (!(p = init_forks(-1, p)))
		return (NULL);
	p->ttd = ft_atoi(av[2]);
	p->tte = ft_atoi(av[3]);
	p->tts = ft_atoi(av[4]);
	if (ac < 6)
		p->noe = -1;
	else
		p->noe = ft_atoi(av[5]);
	pthread_mutex_init(&p->mutex, NULL);
	while (av[++i])
		if (p->nphils < 2 || !isalldigit(av[i]))
			p->error = 1;
	return (p);
}

void			init_philos(t_params *p)
{
	struct timeval	actual;
	int				i;

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
	}
}
