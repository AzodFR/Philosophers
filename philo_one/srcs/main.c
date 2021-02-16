/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/16 13:21:47 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

int		check_life(t_params *p)
{
	int i;

	i = -1;
	while (++i < p->nphils)
	{
		if (p->philo[i]->eat == 0)
		{
			prefix(p);
			printf("Philosophe %d died\n", i);
			return (0);
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_params *p;
	
	p = init_params(ac, av);
	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !", p));
	print_params(p);
	init_philos(p);
	while (check_life(p))
		;
	free(p->fork);
	free(p->philo);
	free(p);
	return (0);
}