/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:13:32 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/01 17:31:35 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philthree.h"

t_params		*init_forks(t_params *p)
{
	if (!(p->forks = sem_open("forks", O_CREAT, 0660, p->nphils)))
		return (NULL);
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
	if (!(p->pid = malloc(p->nphils * sizeof(int))))
		return (NULL);
	if (!(p->mutex = sem_open("main", 0)))
		return (NULL);
	if (!(p = init_forks(p)))
		return (NULL);
	p->ttd = ft_atoi(av[2]);
	p->tte = ft_atoi(av[3]);
	p->tts = ft_atoi(av[4]);
	if (ac < 6)
		p->noe = -1;
	else
		p->noe = ft_atoi(av[5]);
	while (av[++i])
		p->error = (p->nphils < 2 || !isalldigit(av[i])) ? 1 : p->error;
	return (p);
}

void			*launch(void *p)
{
	int		pid;

	if (!(pid = fork()))
		simulate(p);
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
		p->philo[i]->mutex = sem_open("philo", 0);
		p->pid[i] = fork();
		if (!p->pid[i])
			simulate(&(p->philo[i]));
		usleep(5000);
	}
}
