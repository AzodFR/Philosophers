/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philone.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:45 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/16 13:05:29 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILONE_H
# define PHILONE_H
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_philos
{
	int				id;
	int				eat;
	pthread_t		thread;
	struct s_params *p;
}					t_philos;


typedef struct		s_params
{
	struct timeval	start;
	int				nphils;
	int				ttd;
	int				tte;
	int				tts;
	int				noe;
	pthread_mutex_t	**fork;
	t_philos		**philo;
}					t_params;
/*
**	UTILS.C
*/
int			ft_atoi(const char *nbtr);
int			print_error(char *s, t_params *p);
void		prefix(t_params *p);
void		print_action(t_philos *p, char *s);
/*
**	INITER.C
*/
void		init_philos(t_params *p);
t_params	*init_params(int ac, char **av);
/*
**	ACTIONS.C
*/
void	sleeping(t_philos *p);
void	thinking(t_philos *p);
void	*simulate(void *philo);
/*
**	DEBUG.C
*/
void	print_params(t_params *p);
#endif