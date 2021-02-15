/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philone.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:00:45 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/15 15:20:00 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILONE_H
# define PHILONE_H
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct		s_params
{
	struct timeval	start;
	int				phils;
	int				forks;
	int				ttd;
	int				tte;
	int				tts;
	int				noe;
}					t_params;
int			ft_atoi(const char *nbtr);
int			print_error(char *s, t_params *p);
void		prefix(t_params *p);
#endif