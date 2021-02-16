/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/16 11:17:57 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

t_params	*init_params(int ac, char **av)
{
	t_params	*p;

	if (!(p = malloc(sizeof(t_params))))
		return (NULL);
	gettimeofday(&p->start, NULL);
	if (ac < 5 || ac > 6)
		return (p);
	p->nphils = ft_atoi(av[1]);
	if (!(p->philo = malloc(p->nphils * sizeof(t_philos))))
		return (NULL);
	if (!(p->fork = malloc(p->nphils * sizeof(pthread_mutex_t *))))
		return (NULL);
	p->ttd = ft_atoi(av[2]);
	p->tte = ft_atoi(av[3]);
	p->tts = ft_atoi(av[4]);
	if (ac < 6)
		p->noe = -1;
	else
		p->noe = ft_atoi(av[5]);
	return (p);
}

void	print_params(t_params *p)
{
	prefix(p);
	printf("\033[34mN of Philo and Forks: \033[92m%d\033[0m\n", p->nphils);
	prefix(p);
	printf("\033[34mTime to die: \033[92m%d\033[0m\n", p->ttd);
	prefix(p);
	printf("\033[34mTime to eat: \033[92m%d\033[0m\n", p->tte);
	prefix(p);
	printf("\033[34mTime to sleep: \033[92m%d\033[0m\n", p->tts);
	prefix(p);
	printf("\033[34mNumber of eating max: \033[92m%d\033[0m\n", p->noe);
}

void	*simu(void *philo)
{
	t_philos	*p;
	
	p = philo;
	while (1)
	{
		usleep(p->tts * 1000 + (p->p->nphils - p->id * 1000000));
		prefix(p->p);
		printf("Philo %d is now sleeping zzZZ\n", p->id);
		usleep(p->tts * 1000 + (p->p->nphils - p->id * 1000000));
		prefix(p->p);
		printf("Philo %d wake up !\n", p->id);
	}
	return (philo);
}

void	init_philos(t_params *p)
{
	int		i;

	i = -1;
	while (++i < p->nphils)
	{
		p->philo[i].id = i;
		p->philo[i].tts = p->tts;
		p->philo[i].p = p;
		pthread_create(&p->philo[i].thread, NULL, simu, &p->philo[i]);
	}
	i = -1;
	while (++i < p->nphils)
		pthread_join(p->philo[i].thread, NULL);
}

int		main(int ac, char **av)
{
	t_params *p;
	
	p = init_params(ac, av);
	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !", p));
	print_params(p);
	init_philos(p);
	free(p);
	return (0);
}