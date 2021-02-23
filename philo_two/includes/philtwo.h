/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philtwo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:45 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/23 15:14:28 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILTWO_H
# define PHILTWO_H
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_philos
{
	sem_t			*mutex;
	int				id;
	int				eat;
	double				deadtime;
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
	int				error;
	int				end;
	sem_t			*mutex;
	sem_t			*forks;
	t_philos		**philo;
}					t_params;
/*
**	UTILS.C
*/
int			ft_atoi(const char *nbtr);
int			print_error(char *s, t_params *p);
void		prefix(t_params *p);
void		print_action(t_philos *p, char *s);
double			get_time(t_params *p);
/*
**	INITER.C
*/
void		init_philos(t_params *p);
t_params	*init_params(int i, int ac, char **av);
/*
**	ACTIONS.C
*/
void	sleeping(t_philos *p);
void	thinking(t_philos *p);
void	*simulate(void *philo);
int		is_alive(t_philos *p);
/*
**	DEBUG.C
*/
void	print_params(t_params *p);
int		check_time(int	time, t_params *p);
int		isalldigit(char *s);
#endif