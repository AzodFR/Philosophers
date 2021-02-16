/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:58:35 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/16 13:22:32 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philone.h"

void	sleeping(t_philos *p)
{
	print_action(p, "is sleeping");
	usleep(p->p->tts * 1000);
}

void	thinking(t_philos *p)
{
	print_action(p, "is thinking");
	usleep(p->p->tts * 1000);
}

void	*simulate(void *philo)
{
	t_philos	**p;
	
	p = philo;
	while ((*p)->eat != 0)
	{
		//printf("\033[92m Philo %d -> eat: %d\033[0m\n", (*p)->id, (*p)->eat);
		sleeping(*p);
		thinking(*p);
		(*p)->eat -= 1;
	}
	prefix((*p)->p);
	printf("died\n");
	return (philo);
}