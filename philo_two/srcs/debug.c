/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thjacque <thjacque@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:12:58 by thjacque          #+#    #+#             */
/*   Updated: 2021/02/23 15:14:02 by thjacque         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philtwo.h"

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

int		isalldigit(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] < '0' || s[i] > '9')
			return (0);
	return (1);
}
