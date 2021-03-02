/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philtwo.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:45 by thjacque          #+#    #+#             */
/*   Updated: 2021/03/02 10:39:23 by thjacque         ###   ########lyon.fr   */
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
	double				ttd;
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
void	*simulate(void *philo);
int		is_alive(t_philos *p);
/*
**	DEBUG.C
*/
void	print_params(t_params *p);
int		check_time(int	time, t_params *p);
int		isalldigit(char *s);
void	stopping(t_params *p);
void		unlink_sem(void);

t_params	*get_p(t_params *p);
#endif