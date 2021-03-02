/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:59:56 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/02 10:59:08 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philthree.h"

int				check_time(int time, t_params *p)
{
	struct timeval	actual;

	gettimeofday(&actual, NULL);
	if (time >= get_time(p) - 5)
		return (1);
	return (0);
}

static void		check_life(t_params *p)
{
	int		i;
	int		status;
	pid_t	tmp;

	i = -1;
	while (++i != p->nphils)
	{
		status = 0;
		tmp = -1;
		while (!status && tmp <= 0)
			tmp = waitpid(-1, &status, 0);
		if (status == 256)
			break ;
	}
	if (status == 256)
	{
		i = -1;
		while (++i < p->nphils)
			if (tmp != p->pid[i])
				kill(p->pid[i], SIGKILL);
			else
				print_action(p->philo[i], "died");
	}
	stopping(p);
}

t_params		*get_p(t_params *p)
{
	static t_params *pa = NULL;

	if (p)
		pa = p;
	return (pa);
}

void			unlink_sem(void)
{
	sem_unlink("main");
	sem_unlink("forks");
	sem_unlink("philo");
}

int				main(int ac, char **av)
{
	t_params	*p;

	unlink_sem();
	if (ac < 5 || ac > 6)
		return (print_error("Incorrect number of arguments !", NULL));
	if (!(p = init_params(0, ac, av)))
		return (print_error("Malloc error !", NULL));
	if (p->error)
		return (print_error("Invalid(s) parameter(s) !", p));
	p->end = 0;
	get_p(p);
	init_philos(p);
	check_life(p);
	return (0);
}
