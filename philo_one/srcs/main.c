/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/15 15:16:40 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

t_params	*init_params(int ac, char **av)
{
	t_params	*p;

	if (!(p = malloc(sizeof(t_params))))
		return (NULL);
	gettimeofday(&p->start, NULL);
	p->phils = ft_atoi(av[1]);
	p->forks = ft_atoi(av[1]);
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
	printf("\033[34mN of Philo and Forks: \033[92m%d\033[0m\n", p->phils);
	prefix(p);
	printf("\033[34mTime to die: \033[92m%d\033[0m\n", p->ttd);
	prefix(p);
	printf("\033[34mTime to eat: \033[92m%d\033[0m\n", p->tte);
	prefix(p);
	printf("\033[34mTime to sleep: \033[92m%d\033[0m\n", p->tts);
	prefix(p);
	printf("\033[34mNumber of eating max: \033[92m%d\033[0m\n", p->noe);
}

int		main(int ac, char **av)
{
	t_params *p;
	
	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !"));
	p = init_params(ac, av);
	print_params(p);
	free(p);
	return (0);
}